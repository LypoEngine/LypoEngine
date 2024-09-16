//
// Created by samuel on 9/16/24.
//

#include "window_configuration.h"

void hive::WindowConfiguration::set(const WindowConfigurationOptions flag, const bool value) {
    m_windowFlags[static_cast<int>(flag)] = value;
}

bool hive::WindowConfiguration::has(const WindowConfigurationOptions flag) {
    return m_windowFlags[static_cast<int>(flag)];
}

void hive::WindowConfiguration::toggle(const WindowConfigurationOptions flag) {
    m_windowFlags[static_cast<int>(flag)] = !m_windowFlags[static_cast<int>(flag)];
}

void hive::WindowConfiguration::clear() {
    m_windowFlags.reset();
}

hive::WindowConfiguration hive::WindowConfiguration::operator^(const WindowConfiguration &other) const {
    WindowConfiguration result;
    result.m_windowFlags = this->m_windowFlags ^ other.m_windowFlags;
    return result;
}

