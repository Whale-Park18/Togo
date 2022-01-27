#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "../../backup/core.h"

namespace togo {
namespace cli {
namespace command {

class AbstractCommand
{
public:
	AbstractCommand(std::vector<std::string> options, std::map<std::string, std::string> input_options_mapping)
		: kOptions_(options), input_options_mapping_(input_options_mapping) {};

	virtual void Execute() = 0;

protected:
	virtual bool IsOptionCorrect() = 0;
	bool HaveOption(std::string option)
	{
		if (std::find(kOptions_.begin(), kOptions_.end(), option) == kOptions_.end())
			return false;

		return true;
	}

protected:
	const std::vector<std::string> kOptions_;
	std::map<std::string, std::string> input_options_mapping_;
};

} // namespace command
} // namespace cli
} // namespace togo