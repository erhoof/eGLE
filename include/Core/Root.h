//
// Created by Pavel Bibichenko on 31.10.2020.
//

#ifndef EGLE_ROOT_H
#define EGLE_ROOT_H

#include <map>
#include <string>

namespace eGLE
{
    class SceneManager;

    class Root {
    public:
        Root();

        SceneManager *createSceneManager();
        SceneManager *sceneManager(std::string name);
        bool removeSceneManager(std::string name);

        void queueEndRendering();

    private:
        bool m_isActive;
        std::map<std::string, SceneManager *> m_sceneManagers;
    };
}

#endif //EGLE_ROOT_H
