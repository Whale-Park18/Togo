#include "add_command.h"

int togo::cli::command::AddCommand::CheckOptions()
{
    for (auto pair : input_options_mapping_)
    {
        if (HaveOption(pair.first))
        {
            
        }
        else
            return 1; // todo: error �ڵ�, ���� ����
    }

    return 0;
}
