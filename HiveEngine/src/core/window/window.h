//
// Created by GuillaumeIsCoding on 7/26/2024.
//
#pragma once


namespace hive {
    class WindowConfiguration;
}

namespace hive
{
    class Window {
    public:
        virtual ~Window() = default;

        [[nodiscard]] virtual int getHeight() const = 0;
        [[nodiscard]] virtual void* getNativeWindow() const = 0;
        [[nodiscard]] virtual int getWidth() const = 0;
        virtual void onUpdate() const = 0;
        virtual void setIcon(unsigned char* data, int width, int height) const = 0;
        [[nodiscard]] virtual bool shouldClose() const = 0;
        virtual void updateConfiguration(WindowConfiguration configuration) = 0;
    };
}
