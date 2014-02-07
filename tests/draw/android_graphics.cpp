/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Kevin DuBois <kevin.dubois@canonical.com>
 */


#include "mir_test/draw/android_graphics.h"
#include "mir_toolkit/common.h"

#include <fstream>
#include <stdexcept>
#include <dirent.h>
#include <fnmatch.h>

namespace mtd=mir::test::draw;
namespace mc=mir::compositor;
namespace geom=mir::geometry;

namespace
{
struct RegionDeleter
{
    RegionDeleter(gralloc_module_t* grmod, native_handle_t const* handle)
     : grmod(grmod),
       handle(handle)
    {
    }

    void operator()(MirGraphicsRegion* region)
    {
        grmod->unlock(grmod, handle);
        delete region;
    }

    gralloc_module_t *grmod;
    native_handle_t const* handle;
};
}

mtd::TestGrallocMapper::TestGrallocMapper()
 : gralloc_ownership(true)
{
    const hw_module_t *hw_module;
    if (hw_get_module(GRALLOC_HARDWARE_MODULE_ID, &hw_module) != 0)
        throw std::runtime_error("error, hw module not available!\n");
    gralloc_open(hw_module, &alloc_dev);
    module = (gralloc_module_t*) hw_module;
}

mtd::TestGrallocMapper::TestGrallocMapper(const hw_module_t *hw_module,
                                     alloc_device_t* alloc_dev)
 : gralloc_ownership(false),
   module((gralloc_module_t*)hw_module),
   alloc_dev(alloc_dev)
{
}

mtd::TestGrallocMapper::~TestGrallocMapper()
{
    if (gralloc_ownership)
        gralloc_close(alloc_dev);
}

std::shared_ptr<MirGraphicsRegion> mtd::TestGrallocMapper::graphic_region_from_handle(
    ANativeWindowBuffer* package)
{
    int *vaddr;
    int usage = GRALLOC_USAGE_SW_READ_OFTEN | GRALLOC_USAGE_SW_WRITE_OFTEN;
    module->lock(module, package->handle, usage, 0, 0, package->width, package->height, (void**) &vaddr);

    MirGraphicsRegion* region = new MirGraphicsRegion;
    RegionDeleter del(module, package->handle);

    region->vaddr = (char*) vaddr;
   region->stride = package->stride * MIR_BYTES_PER_PIXEL(mir_pixel_format_abgr_8888);
    region->width = package->width;
    region->height = package->height;
    region->pixel_format = mir_pixel_format_abgr_8888;

    return std::shared_ptr<MirGraphicsRegion>(region, del);
}
