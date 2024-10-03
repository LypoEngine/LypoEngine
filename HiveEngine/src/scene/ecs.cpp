//
// Created by samuel on 9/27/24.
//

#include "ecs.h"

#include "system_manager.h"

std::unique_ptr<hive::SystemManager> hive::ECS::m_systemManager	= nullptr;
std::shared_ptr<entt::registry> hive::ECS::m_registry = nullptr;

void hive::ECS::init()
{
	Logger::log("Initialising ECS", LogLevel::Debug);

	m_registry = std::make_shared<entt::registry>();
	m_systemManager = std::make_unique<SystemManager>();
}

void hive::ECS::shutdown()
{
	Logger::log("Shutting down ECS", LogLevel::Debug);
	m_systemManager.reset();
	m_registry.reset();
}

void hive::ECS::registerSystem(System* system, const std::string& name)
{
	m_systemManager->registerSystem(system, name);
}


void hive::ECS::updateSystems(float deltaTime)
{
	m_systemManager->updateSystems(deltaTime);
}

hive::Entity hive::ECS::createEntity()
{
	return m_registry->create();
}



