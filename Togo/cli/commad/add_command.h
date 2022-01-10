#pragma once

#include "abstract_command.h"
#include "../../backup/core.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace togo {
namespace cli {
namespace command {

class AddCommand : public AbstractCommand
{
public:
	AddCommand(std::map<std::string, std::string> input_options_mapping)
		: AbstractCommand(std::vector<std::string>{"--source", "--destinaiton"}, input_options_mapping) {};

	virtual void Execute();

protected:
	virtual bool CheckOptions();
	bool IsExist(boost::filesystem::path);

private:
	boost::filesystem::path source_;
	boost::filesystem::path destination_;
	backup::core::ConfingureManager configureManager_;
};

} // namespace command
} // namespace cli
} // namespace togo