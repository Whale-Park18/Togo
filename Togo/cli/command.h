#pragma once

#include "commad/abstract_command.h"
#include "commad/add_command.h"
#include "commad/backup_command.h"
#include "commad/list_command.h"
#include "commad/remove_commabd.h"
#include "commad/setting_commabd.h"

namespace togo {
namespace cli {
namespace command {

	AbstractCommand* CommandFilt(std::string command, std::map<std::string, std::string> input_options_mapping)
	{
		AbstractCommand* command_master;

		if (command._Equal("add"))
			command_master = new AddCommand(input_options_mapping);
		else if (command._Equal("run"))
			command_master = new BackupCommand(input_options_mapping);
		else if (command._Equal("list"))
			command_master = new ListCommand(input_options_mapping);
		else if (command._Equal("rm"))
			command_master = new RemoveCommand(input_options_mapping);
		else if (command._Equal("set"))
			command_master = new SettingCommand(input_options_mapping);
		else
			command_master = nullptr;

		return command_master;
	}

} // namespace command
} // namespace cli
} // namespace togo
