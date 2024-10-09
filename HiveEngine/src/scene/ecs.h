//
// Created by samuel on 9/27/24.
//

#pragma once
#include <entt/entt.hpp>

#include "system_manager.h"

namespace hive
{
	class System;
	class SystemManager;
}

namespace hive
{

    using Entity = entt::entity;
	using Registry = entt::registry;

	class ECS
	{
	public:
		static void init();
		static void shutdown();

		//System
		static void registerSystem(System* system, const std::string &name);
		static void updateSystems(float deltaTime);


		//Entity
		template <typename T, typename... Args>
		static T& addComponent(Entity entity, Args&&... args)
		{
			assert(!hasComponent<T>(entity));
			return m_registry->emplace<T>(entity, std::forward<Args>(args)...);
		}

		template <typename T>
		void removeComponent(const Entity entity)
		{
			assert(hasComponent<T>(entity));
			m_registry->remove<T>(entity);
		}

        template<typename T, typename... Args>
        T& replaceComponent(Entity entity, Args&&... args)
        {
            return m_registry->emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        }


		template <typename T>
		T& getComponent(const Entity entity)
		{
			assert(hasComponent<T>());
			return m_registry->get<T>(entity);
		}

		template <typename T>
		static bool hasComponent(const Entity entity)
		{
			return m_registry->all_of<T>(entity);
		}

		static Entity createEntity();

		//Other
		static std::shared_ptr<Registry> getCurrentRegistry() { return m_registry; }


	private:
		static std::unique_ptr<SystemManager> m_systemManager;
		static std::shared_ptr<Registry> m_registry;
	};
}
