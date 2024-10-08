//
// Created by samuel on 9/16/24.
//

#pragma once

#include <bitset>

namespace hive {
    enum class WindowConfigurationOptions {
        FULLSCREEN,
        CURSOR_DISABLED
    };

    class WindowConfiguration {
    public:
        void set(WindowConfigurationOptions flag, bool value);

        bool has(WindowConfigurationOptions flag);

        void toggle(WindowConfigurationOptions flag);

        void clear();

        WindowConfiguration operator^(const WindowConfiguration &other) const;

        constexpr static int MAX_BIT = 24;
    private:
        std::bitset<MAX_BIT> m_windowFlags;
    };
}
