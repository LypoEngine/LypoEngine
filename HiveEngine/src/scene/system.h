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

		virtual void init() {};
		virtual void update(float deltaTime) {};

	protected:
		friend class SystemManager;
		bool is_active = true;

	};
}



