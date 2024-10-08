//
// Created by wstap on 8/4/2024.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <map>

namespace hive {
    class InputManager {
    public:
        virtual ~InputManager() = default;

        virtual bool isKeyDown(int key) const = 0;
        virtual bool isKeyUp(int key) const = 0;

        virtual bool isKeyPressed(int key) = 0;
        virtual bool isKeyReleased(int key) = 0;

        virtual bool isMouseButtonDown(int button) const = 0;
        virtual bool isMouseButtonUp(int button) const = 0;

        virtual double getMouseX() const = 0;
        virtual double getMouseY() const = 0;

    protected:
        std::map<int, bool> keyPressState;
        std::map<int, bool> keyReleaseState;
    };
}
#endif //INPUTMANAGER_H
