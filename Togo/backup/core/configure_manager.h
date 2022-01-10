#pragma once

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace togo {
namespace backup {
namespace core {

class ConfingureManager
{
public:
	void AddPath(boost::filesystem::path source, boost::filesystem::path destination);
	void RemovePathAt(int index);
	void RemovePathAll();
	void SetAuto(bool autoValue);
	void SetAutoTime(int time);
	void PrintPathList();

private:
	const std::string kConfingureFile_ = "configure.json";
	const std::string kJsonPathList_ = "togo.pathList";
	const std::string kJsonPathSource_ = "source";
	const std::string kJsonPathDestination_ = "destination";
	const std::string kJsonSettingAuto_ = "togo.setting.auto";
	const std::string kJsonSettingTime_ = "togo.setting.time";
};

} // namespace core
} // namespace backup
} // namespace togo