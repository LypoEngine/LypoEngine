//
// Created by samuel on 9/27/24.
//

#pragma once
#include <entt/entt.hpp>

#include "Registry.h"
#include "system_manager.h"

namespace hive
{
	class System;
	class SystemManager;
}

namespace hive
{

    using Entity = entt::entity;
	using Registry = EntityRegistry;

	class ECS
	{
	public:
		static void init();
		static void shutdown();

		//System
		static void registerSystem(System* system, const std::string &name);
		static void removeSystem(const std::string &name);
		static void updateSystems(float deltaTime);


		//Entity
		template <typename T, typename... Args>
		static void addComponent(Entity entity, Args&&... args)
		{
			assert(!hasComponent<T>(entity));
			return getCurrentRegistry()->addComponent<T>(entity, args...);
		}

		template <typename T>
		void removeComponent(const Entity entity)
		{
			assert(hasComponent<T>(entity));
			getCurrentRegistry()->removeComponent<T>(entity);
		}
        //
        // template<typename T, typename... Args>
        // T& replaceComponent(Entity entity, Args&&... args)
        // {
        //     return getCurrentRegistry()->emplace_or_replace<T>(entity, std::forward<Args>(args)...);
        // }


		template <typename T>
		T& getComponent(const Entity entity)
		{
			assert(hasComponent<T>());
			return getCurrentRegistry()->getComponent<T>(entity);
		}

		template <typename T>
		static bool hasComponent(const Entity entity)
		{
			return getCurrentRegistry()->hasComponent<T>(entity);
		}

		static entt::entity createEntity();

		//Other
		static Registry* getCurrentRegistry();

	private:
		static Registry* m_registry;
	};
}
