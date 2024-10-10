//
// Created by samuel on 9/27/24.
//

#include "system_manager.h"

hive::SystemManager::~SystemManager()
{
	for (const auto& [name, system]: m_systems)
	{
		delete system;
	}
}


void hive::SystemManager::updateSystems(float deltaTime)
{
	for (auto& system_pair : m_systems)
	{
		const std::string name = system_pair.first;
		auto system = system_pair.second;

		if(system->is_active)
		{
			system->update(deltaTime);
		}
	}
}

void hive::SystemManager::registerSystem(System* system, const std::string& name)
{
	m_systems[name] = system;
	system->init();
}

void hive::SystemManager::removeSystem(const std::string& name)
{
	m_systems.erase(name);
}



