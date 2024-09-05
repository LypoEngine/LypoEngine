//
// Created by wstap on 8/4/2024.
//

#include "event.h"

namespace hive {

    void IEventHandler::addChild(IEventHandler* child) {
        child->parent = this;
        children.push_back(child);
        updateBfsPath();
    }

    void IEventHandler::updateBfsPath()
    {
        if(parent != nullptr)
            parent->updateBfsPath();
    }

}