//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_KEYSYM_H
#define EGLE_KEYSYM_H

#include "Keymod.h"
#include "Keycode.h"

namespace eGLEBites
{
    struct Keysym {
        Keymod mod;
        Keycode sym;
    };
}

#endif //EGLE_KEYSYM_H
