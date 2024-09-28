//
// Created by samuel on 9/27/24.
//

#pragma once
#include <map>

#include "system.h"

namespace hive
{
	class SystemManager
	{
	public:
		explicit SystemManager(const std::shared_ptr<Scene>& scene);
		~SystemManager();

		void updateSystems(float deltaTime);

		void registerSystem(System* system, const std::string &name);
		void removeSystem(const std::string &name);

		void setSystemState(const std::string &name, bool state);


	private:
		std::map<std::string, System*> m_systems;
		std::map<std::string, bool> m_systems_state;

		std::shared_ptr<Scene> m_scene;
	};
}
