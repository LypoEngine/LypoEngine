//
// Created by samuel on 9/27/24.
//

#pragma once
#include <entt/entt.hpp>

#include "system_manager.h"

namespace hive
{
	class System;
	class Scene;
	class SystemManager;
}

namespace hive
{
	class ECS
	{
	public:
		static void init();
		static void shutdown();

		static void registerSystem(System* system, const std::string &name);

		static void updateSystems(float deltaTime);

		static std::shared_ptr<Scene> getCurrentScene();

		static entt::registry& getRegistry();

	private:
		static std::unique_ptr<SystemManager> m_systemManager;
		static std::shared_ptr<Scene> m_Scene;
	};
}
