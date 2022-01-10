#include "list_command.h"

void togo::cli::command::ListCommand::Execute()
{
	configureManager_.PrintPathList();
}

int togo::cli::command::ListCommand::CheckOptions()
{
	if (input_options_mapping_.empty())
		return true;

	return false;
}
