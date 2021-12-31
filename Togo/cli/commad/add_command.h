#pragma once

#include "abstract_command.h"

namespace togo {
namespace cli {
namespace command {

class AddCommand : public AbstractCommand
{
public:
	AddCommand(std::map<std::string, std::string> input_options_mapping)
		: AbstractCommand(std::string("add"), std::vector<std::string>{"--source", "--destinaiton"}, input_options_mapping) {};

	virtual void Execute();

protected:
	virtual int CheckOptions();
};

} // namespace command
} // namespace cli
} // namespace togo