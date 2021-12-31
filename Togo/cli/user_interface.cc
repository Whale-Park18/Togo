#include "user_interface.h"

void togo::cli::UserInterface::Launch()
{
	command::AbstractCommand* command_master = command::CommandFilt(input_command_, input_options_mapping_);
	command_master->Execute();
}

void togo::cli::UserInterface::set_input_options_mapping(std::vector<std::string> options)
{
	for (std::string option : options)
	{
		
	}
}
