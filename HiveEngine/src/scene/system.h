//
// Created by samuel on 9/27/24.
//

#pragma once


namespace hive
{
	class SystemManager;
}

namespace hive
{
	class System
	{
	public:

		virtual ~System() = default;

		virtual void init() {};
		virtual void update(float deltaTime) {};
	};
}



