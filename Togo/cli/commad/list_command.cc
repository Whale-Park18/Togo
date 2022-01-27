#include "list_command.h"

void togo::cli::command::ListCommand::Execute()
{
	configureManager_.PrintPathList();
}

bool togo::cli::command::ListCommand::IsOptionCorrect()
{
	if (input_options_mapping_.empty())
		return true;

	return false;
}
