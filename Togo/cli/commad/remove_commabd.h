#pragma once

#include "abstract_command.h"

namespace togo {
namespace cli {
namespace command {

class RemoveCommand : public AbstractCommand
{
public:
	RemoveCommand(std::map<std::string, std::string> input_options_mapping)
		: AbstractCommand(std::string("rm"), std::vector<std::string>{"--all", "--index"}, input_options_mapping) {};

	virtual void Execute();

protected:
	virtual int CheckOptions();
};

} // namespace command
} // namespace cli
} // namespace togo