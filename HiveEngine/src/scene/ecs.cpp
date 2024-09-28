//
// Created by samuel on 9/27/24.
//

#include "ecs.h"

#include "scene.h"
#include "system_manager.h"

std::unique_ptr<hive::SystemManager> hive::ECS::m_systemManager	= nullptr;
std::shared_ptr<hive::Scene> hive::ECS::m_Scene	= nullptr;

void hive::ECS::init()
{
	Logger::log("Initialising ECS", LogLevel::Debug);

	m_Scene = std::make_shared<Scene>();
	m_systemManager = std::make_unique<SystemManager>(m_Scene);
}

void hive::ECS::shutdown()
{
	Logger::log("Shutting down ECS", LogLevel::Debug);
	m_systemManager.reset();
	m_Scene.reset();
}

void hive::ECS::registerSystem(System* system, const std::string& name)
{
	m_systemManager->registerSystem(system, name);
}


void hive::ECS::updateSystems(float deltaTime)
{
	m_systemManager->updateSystems(deltaTime);
}

std::shared_ptr<hive::Scene> hive::ECS::getCurrentScene()
{
	return m_Scene;
}

entt::registry& hive::ECS::getRegistry()
{
	return m_Scene->getRegistry();
}



