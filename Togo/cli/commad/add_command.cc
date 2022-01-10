#include "add_command.h"

void togo::cli::command::AddCommand::Execute()
{
    configureManager_.AddPath(source_, destination_);
}

bool togo::cli::command::AddCommand::CheckOptions()
{
    for (auto pair : input_options_mapping_)
    {
        if (HaveOption(pair.first))
        {
            if (IsExist(pair.second))
                continue;
            else
            {
                // throw: [pair.second], path does not exist
                return false;
            }
        }
            
        else
        {
            // throw: [pair.first], wrong option
        }
    }

    return true;
}

bool togo::cli::command::AddCommand::IsExist(boost::filesystem::path)
{
    return false;
}
