#pragma once

#include "abstract_command.h"

namespace togo {
namespace cli {
namespace command {

class BackupCommand : public AbstractCommand
{
public:
	BackupCommand(std::map<std::string, std::string> input_options_mapping)
		: AbstractCommand(std::vector<std::string>(), input_options_mapping) {};

	virtual void Execute();

protected:
	virtual bool CheckOptions();

private:
	backup::core::Mover mover_;
};

} // namespace command
} // namespace cli
} // namespace togo