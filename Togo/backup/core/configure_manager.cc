#include "configure_manager.h"

namespace bpt = boost::property_tree;
using namespace std;

void togo::backup::core::ConfingureManager::AddPath(boost::filesystem::path source, boost::filesystem::path destination)
{
	try
	{
		bpt::ptree root;
		bpt::read_json(kConfingureFile_, root);

		bpt::ptree path;
		path.put(kJsonPathSource_, source.generic_string());
		path.put(kJsonPathDestination_, destination.generic_string());

		auto& pathList = root.get_child(kJsonPathList_);
		pathList.push_back(make_pair("", path));

		bpt::write_json(kConfingureFile_, root);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

void togo::backup::core::ConfingureManager::RemovePathAt(int index)
{
	bpt::ptree root;
	bpt::read_json(kConfingureFile_, root);

	auto& pathList = root.get_child(kJsonPathList_);
	bpt::ptree::iterator path = pathList.begin();
	for (int i = 0; i < index; i++)
		path++;

	pathList.erase(path);

	bpt::write_json(kConfingureFile_, root);
}

void togo::backup::core::ConfingureManager::RemovePathAll()
{
	bpt::ptree root;
	bpt::read_json(kConfingureFile_, root);

	auto& pathList = root.get_child(kJsonPathList_);
	pathList.clear();

	bpt::write_json(kConfingureFile_, root);
}

void togo::backup::core::ConfingureManager::SetAuto(bool autoValue)
{
	bpt::ptree root;
	bpt::read_json(kConfingureFile_, root);

	root.put(kJsonSettingAuto_, autoValue);

	bpt::write_json(kConfingureFile_, root);
}

void togo::backup::core::ConfingureManager::SetAutoTime(int time)
{
	bpt::ptree root;
	bpt::read_json(kConfingureFile_, root);

	root.put(kJsonSettingTime_, time);

	bpt::write_json(kConfingureFile_, root);
}

void togo::backup::core::ConfingureManager::PrintPathList()
{
	bpt::ptree root;
	bpt::read_json(kConfingureFile_, root);

	auto& pathList = root.get_child(kJsonPathList_);
	int index = 1;
	for (auto& path : pathList)
	{
		cout << "[" << index << "] "
			 << "source: " << path.second.get<std::string>(kJsonPathSource_) << " - "
			 << "destination: " << path.second.get<std::string>(kJsonPathDestination_) << endl;
	}
}
