/*
 * Copyright © 2021 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MIR_FRONTEND_INPUT_METHOD_V2_H
#define MIR_FRONTEND_INPUT_METHOD_V2_H


#include "input-method-unstable-v2_wrapper.h"

#include <memory>

namespace mir
{
class Executor;
namespace scene
{
class TextInputHub;
}
namespace input
{
class CompositeEventFilter;
}
namespace frontend
{
auto create_input_method_manager_v2(
    wl_display* display,
    std::shared_ptr<Executor> const& wayland_executor,
    std::shared_ptr<scene::TextInputHub> const& text_input_hub,
    std::shared_ptr<input::CompositeEventFilter> const event_filter)
-> std::shared_ptr<wayland::InputMethodManagerV2::Global>;
}
}

#endif // MIR_FRONTEND_INPUT_METHOD_V2_H
