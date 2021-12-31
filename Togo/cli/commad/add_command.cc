#include "add_command.h"

int togo::cli::command::AddCommand::CheckOptions()
{
    for (auto pair : input_options_mapping_)
    {
        if (HaveOption(pair.first))
        {
            
        }
        else
            return 1; // todo: error 코드, 추후 수정
    }

    return 0;
}
