#include "backup_command.h"

void togo::cli::command::BackupCommand::Execute()
{
	mover.execute();
}

int togo::cli::command::BackupCommand::CheckOptions()
{
	if (input_options_mapping_.empty())
		return true;

	return false;
}
