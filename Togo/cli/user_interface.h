#pragma once

#include "command.h"

#define COMMAND_POINTER 0
#define OPTION_START_POINTER 1

namespace togo {
namespace cli {

class UserInterface
{
public:
	UserInterface(std::vector<std::string> command_line) : input_command_(command_line[COMMAND_POINTER])
	{
		set_input_options_mapping(std::vector<std::string>(command_line.begin() + OPTION_START_POINTER, command_line.end()));
	}

	void Execute();

private:
	void set_input_options_mapping(std::vector<std::string> options);

private:
	std::string input_command_;
	std::map<std::string, std::string> input_options_mapping_;

};

} // namespace cli
} // namespace togo