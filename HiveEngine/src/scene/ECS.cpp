//
// Created by samuel on 9/27/24.
//

#include "ECS.h"

#include "system_manager.h"

// std::unique_ptr<hive::SystemManager> hive::ECS::m_systemManager	= nullptr;
hive::SystemManager *m_systemManager = nullptr;
hive::Registry *hive::ECS::m_registry = nullptr;


void hive::ECS::init()
{
	Logger::log("Initialising ECS", LogLevel::Debug);

	m_registry = new Registry();
	m_systemManager = new SystemManager();
}

void hive::ECS::shutdown()
{
	Logger::log("Shutting down ECS", LogLevel::Debug);
	delete m_systemManager;
	delete m_registry;
}

void hive::ECS::registerSystem(System* system, const std::string& name)
{
	m_systemManager->registerSystem(system, name);
}

void hive::ECS::removeSystem(const std::string& name)
{
	m_systemManager->removeSystem(name);
}


void hive::ECS::updateSystems(float deltaTime)
{
	m_systemManager->updateSystems(deltaTime);
}

entt::entity hive::ECS::createEntity()
{
	return m_registry->createEntity();
}

hive::Registry* hive::ECS::getCurrentRegistry()
{
	return m_registry;
}



//================================================





