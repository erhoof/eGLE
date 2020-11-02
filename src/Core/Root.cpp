//
// Created by Pavel Bibichenko on 31.10.2020.
//

#include "../../include/Core/Root.h"

namespace eGLE
{
    Root::Root() {
        m_isActive = true;
    }

    SceneManager *Root::createSceneManager() {
        return nullptr;
    }

    SceneManager *Root::sceneManager(std::string name) {
        auto it = m_sceneManagers.find(name);

        if (it != m_sceneManagers.end())
            return m_sceneManagers[name];

        return nullptr;
    }

    bool Root::removeSceneManager(std::string name) {
        auto it = m_sceneManagers.find(name);

        if (it != m_sceneManagers.end()) {
            m_sceneManagers.erase(it);
            return true;
        }

        return false;
    }

    void Root::queueEndRendering() {
        m_isActive = false;
    }
}