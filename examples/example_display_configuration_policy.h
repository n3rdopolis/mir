/*
 * Copyright © 2014 Canonical Ltd.
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
 *
 * Authored By: Alan Griffiths <alan@octopull.co.uk>
 */

#ifndef MIR_EXAMPLE_DISPLAY_CONFIGURATION_POLICY_H_
#define MIR_EXAMPLE_DISPLAY_CONFIGURATION_POLICY_H_

#include "mir/graphics/display_configuration_policy.h"

namespace mir
{
namespace examples
{
extern char const* const display_config_opt;
extern char const* const display_config_descr;
extern char const* const clone_opt_val;
extern char const* const sidebyside_opt_val;
extern char const* const single_opt_val;

class SideBySideDisplayConfigurationPolicy : public graphics::DisplayConfigurationPolicy
{
public:
    void apply_to(graphics::DisplayConfiguration& conf);
};

class SingleDisplayConfigurationPolicy : public graphics::DisplayConfigurationPolicy
{
public:
    void apply_to(graphics::DisplayConfiguration& conf);
};
}
}

#endif /* MIR_EXAMPLE_DISPLAY_CONFIGURATION_POLICY_H_ */
