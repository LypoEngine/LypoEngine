//
// Created by samuel on 10/2/24.
//

#include "WindowManager.h"

#include <cassert>


std::shared_ptr<hive::Window> hive::WindowManager::m_window = nullptr;

std::shared_ptr<hive::Window> hive::WindowManager::getCurrentWindow()
{
	assert(m_window != nullptr);
	return m_window;
}

void hive::WindowManager::setCurrentWindow(const std::shared_ptr<Window>& window)
{
	m_window = window;
}
