//
// Created by samuel on 10/9/24.
//

#ifndef REGISTRY_H
#define REGISTRY_H

#include <entt/entt.hpp>

namespace hive
{
	class EntityRegistry
	{
	public:
		using Entity = entt::entity;

		EntityRegistry() = default;

		// Create a new entity
		Entity createEntity()
		{
			return registry.create();
		}

		// Add a component to an entity
		template <typename Component, typename... Args>
		void addComponent(Entity entity, Args&&... args)
		{
			registry.emplace<Component>(entity, std::forward<Args>(args)...);
		}

		// Check if an entity has a component
		template <typename Component>
		bool hasComponent(Entity entity) const
		{
			return registry.all_of<Component>(entity);
		}

		// Optional: Retrieve a component from an entity
		template <typename Component>
		Component& getComponent(Entity entity)
		{
			return registry.get<Component>(entity);
		}

		// Optional: Remove a component from an entity
		template <typename Component>
		void removeComponent(Entity entity)
		{
			registry.remove<Component>(entity);
		}

	protected:
		template <typename... Component>
		friend class QueryBuilder;
		entt::registry registry;
	};
}

#endif //REGISTRY_H
