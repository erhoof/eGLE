//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_INPUTLISTENER_H
#define EGLE_INPUTLISTENER_H

#include "KeyboardEvent.h"

namespace eGLEBites
{
    class InputListener {
    public:
        virtual bool keyPressed(const eGLEBites::KeyboardEvent &event);

    private:
    };
}

#endif //EGLE_INPUTLISTENER_H
