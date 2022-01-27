#include "backup_command.h"

void togo::cli::command::BackupCommand::Execute()
{
	mover_.execute();
}

bool togo::cli::command::BackupCommand::IsOptionCorrect()
{
	if (input_options_mapping_.empty())
		return true;

	return false;
}
