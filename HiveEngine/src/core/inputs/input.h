//
// Created by samuel on 9/16/24.
//

#pragma once
#include "keycode.h"


namespace hive
{
    struct WindowNativeData;
}

namespace hive {
    class Window;
}

namespace hive {
    class Input {
    public:
        static void init(WindowNativeData window_native_data);
        static void shutdown();

        static bool getKey(KeyCode key_code);
        static bool getKeyDown(KeyCode key_code);
        static bool getKeyUp(KeyCode key_code);

        //TODO implement mouse input
    };
}

