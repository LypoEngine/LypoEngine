//
// Created by samuel on 10/1/24.
//

#ifndef QUERY_BUILDER_H
#define QUERY_BUILDER_H

#include <entt/entt.hpp>
#include "ecs.h"

namespace hive
{
	template <typename... Components>
	class QueryBuilder
	{
	public:
		QueryBuilder() = default;

		//Return an iterator of a tuple of type <hive::Entity, Components...>
		auto each() const
		{
			auto m_view = ECS::getCurrentRegistry()->view<Components...>();
			return m_view.each();
		}
	};
}



#endif //QUERY_BUILDER_H
