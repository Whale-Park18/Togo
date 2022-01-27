#include "add_command.h"

void togo::cli::command::AddCommand::Execute()
{
    if (IsOptionCorrect())
        configureManager_.AddPath(source_, destination_);

    else
        // 임시 에러 출력 코드
        std::cerr << "error" << std::endl;
}

bool togo::cli::command::AddCommand::IsOptionCorrect()
{
    for (auto& pair : input_options_mapping_)
    {
        if (HaveOption(pair.first))
        {
            boost::filesystem::path path(pair.second);
            if (IsExist(path))
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

bool togo::cli::command::AddCommand::IsExist(boost::filesystem::path& path)
{
    return boost::filesystem::exists(path);
}
