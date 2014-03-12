/*
 * Copyright © 2014 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored By: Alan Griffiths <alan@octopull.co.uk>
 */

#ifndef MIR_OPTIONS_CONFIGURATION_H_
#define MIR_OPTIONS_CONFIGURATION_H_

#include "mir/options/program_option.h"

#include <memory>

namespace mir
{
namespace options
{
extern char const* const server_socket_opt;
extern char const* const no_server_socket_opt;
extern char const* const enable_input_opt;
extern char const* const session_mediator_report_opt;
extern char const* const msg_processor_report_opt;
extern char const* const compositor_report_opt;
extern char const* const display_report_opt;
extern char const* const legacy_input_report_opt;
extern char const* const connector_report_opt;
extern char const* const scene_report_opt;
extern char const* const input_report_opt;
extern char const* const host_socket_opt;
extern char const* const frontend_threads_opt;

extern char const* const name_opt;
extern char const* const offscreen_opt;

extern char const* const glog;
extern char const* const glog_stderrthreshold;
extern char const* const glog_minloglevel;
extern char const* const glog_log_dir;

extern char const* const off_opt_value;
extern char const* const log_opt_value;
extern char const* const lttng_opt_value;

extern char const* const platform_graphics_lib;

class Configuration
{
public:
    virtual std::shared_ptr<options::Option> the_options() const = 0;

protected:

    Configuration() = default;
    virtual ~Configuration() = default;
    Configuration(Configuration const&) = delete;
    Configuration& operator=(Configuration const&) = delete;
};

class AppendableConfiguration
{
public:
    virtual void add_option_int(
        std::string const& option_name, std::string const& description, int) = 0;
    virtual void add_option_string(
        std::string const& option_name, std::string const& description, std::string) = 0;

protected:
    AppendableConfiguration() = default;
    virtual ~AppendableConfiguration() = default;
    AppendableConfiguration(AppendableConfiguration const&) = delete;
    AppendableConfiguration& operator=(AppendableConfiguration const&) = delete;
};
}
}

#endif /* MIR_OPTIONS_CONFIGURATION_H_ */
