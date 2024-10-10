//
// Created by samuel on 9/27/24.
//

#pragma once


namespace hive
{
	class System
	{
	public:

		virtual ~System() = default;

		virtual void init() = 0;
		virtual void update(float deltaTime) = 0;

		bool is_active = true;
	protected:
		friend class SystemManager;

	};
}



