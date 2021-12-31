#pragma once

#include "abstract_command.h"

namespace togo {
namespace cli {
namespace command {

class ListCommand : public AbstractCommand
{
public:
	ListCommand(std::map<std::string, std::string> input_options_mapping)
		: AbstractCommand(std::string("list"), std::vector<std::string>(), input_options_mapping) {};

	virtual void Execute();

protected:
	virtual int CheckOptions();
};

} // namespace command
} // namespace cli
} // namespace togo