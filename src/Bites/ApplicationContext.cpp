//
// Created by Pavel Bibichenko on 02.11.2020.
//

#include "../../include/Bites/ApplicationContext.h"

namespace eGLEBites
{
    ApplicationContext::ApplicationContext() {
        m_appName = "eGLE Application";
    }

    ApplicationContext::ApplicationContext(std::string appName) {
        m_appName = appName;
    }

    eGLE::Root *ApplicationContext::getRoot() {
        return nullptr;
    }

    void ApplicationContext::setup() {

    }

    void ApplicationContext::addInputListener(InputListener *listener) {

    }
}