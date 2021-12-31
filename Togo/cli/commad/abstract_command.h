#pragma once

#include <string>
#include <vector>
#include <map>

namespace togo {
namespace cli {
namespace command {

class AbstractCommand
{
public:
	AbstractCommand(std::string command, std::vector<std::string> options, std::map<std::string, std::string> input_options_mapping)
		: kCommand_(command), kOptions_(options), input_options_mapping_(input_options_mapping) {};

	virtual void Execute() = 0;

protected:
	virtual int CheckOptions() = 0;

protected:
	const std::string kCommand_;
	const std::vector<std::string> kOptions_;
	std::map<std::string, std::string> input_options_mapping_;
};

} // namespace command
} // namespace cli
} // namespace togo