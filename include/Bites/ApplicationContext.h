//
// Created by Pavel Bibichenko on 30.10.2020.
//

#ifndef EGLE_APPLICATIONCONTEXT_H
#define EGLE_APPLICATIONCONTEXT_H

#include <string>

namespace eGLE
{
    class Root;
}

namespace eGLEBites
{
    class InputListener;

    class ApplicationContext {
    public:
        ApplicationContext();
        explicit ApplicationContext(std::string appName);

        eGLE::Root *getRoot();

    protected:
        void setup();
        void addInputListener(InputListener *listener);

    private:
        std::string m_appName;
    };
}

#endif //EGLE_APPLICATIONCONTEXT_H
