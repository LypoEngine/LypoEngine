//
// Created by samuel on 9/27/24.
//

#include "system_manager.h"

#include <assert.h>

hive::SystemManager::SystemManager(const std::shared_ptr<Scene>& scene): m_scene(scene)
{
}

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

		assert(m_systems_state.contains(name));
		//Only execute systems that are active
		if(m_systems_state[name])
		{
			system->update(deltaTime);
		}
	}
}

void hive::SystemManager::registerSystem(System* system, const std::string& name)
{
	m_systems[name] = system;
	m_systems_state[name] = true;
	system->init();
}

void hive::SystemManager::removeSystem(const std::string& name)
{
	m_systems_state.erase(name);
	m_systems.erase(name);
}

void hive::SystemManager::setSystemState(const std::string& name, const bool state)
{
	assert(m_systems_state.contains(name));
	m_systems_state[name] = state;
}


