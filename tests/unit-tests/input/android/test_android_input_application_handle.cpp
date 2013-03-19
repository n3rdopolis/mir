/*
 * Copyright © 2013 Canonical Ltd.
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
 * Authored by: Robert Carr <robert.carr@canonical.com>
 */

#include "src/server/input/android/android_input_application_handle.h"

#include "mir/frontend/surface_creation_parameters.h"
#include "mir/frontend/session.h"

#include "mir_test/fake_shared.h"
#include "mir_test_doubles/mock_session.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <limits.h>

namespace mia = mir::input::android;
namespace mf = mir::frontend;
namespace mt = mir::test;
namespace mtd = mir::test::doubles;


TEST(AndroidInputApplicationHandle, takes_name_from_session_and_specifies_max_timeout)
{   
    using namespace ::testing;
    std::string const testing_session_name = "Cats";
    mtd::MockSession session;

    EXPECT_CALL(session, name()).Times(AtLeast(1))
        .WillRepeatedly(Return(testing_session_name));
    mia::InputApplicationHandle application_handle(mt::fake_shared(session));
    EXPECT_TRUE(application_handle.updateInfo());
    auto info = application_handle.getInfo();
    EXPECT_EQ(INT_MAX, info->dispatchingTimeout);
    EXPECT_EQ(droidinput::String8(testing_session_name.c_str()), info->name);
}


