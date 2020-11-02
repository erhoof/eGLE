//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_KEYBOARDEVENT_H
#define EGLE_KEYBOARDEVENT_H

#include "Keysym.h"

namespace eGLEBites
{
    struct KeyboardEvent {
        Keysym keysym;
        unsigned char repeat; // non zero if repeats

        enum class type {
            KEYDOWN,
            KEYUP
        } type;
    };
}

#endif //EGLE_KEYBOARDEVENT_H
