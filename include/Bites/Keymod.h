//
// Created by Pavel Bibichenko on 02.11.2020.
//

#ifndef EGLE_KEYMOD_H
#define EGLE_KEYMOD_H

namespace eGLEBites
{
    enum class Keymod {
        KMOD_NONE,
        KMOD_LSHIFT,
        KMOD_RSHIFT,
        KMOD_LCTRL,
        KMOD_RCTRL,
        KMOD_LALT,
        KMOD_RALT,
        KMOD_LMETA,
        KMOD_RMETA,
        KMOD_NUM, // NumLock is down
        KMOD_CAPS, // CapsLock is down
        KMOD_MODE, // Mode is down
        KMOD_CTRL, // Control key is down
        KMOD_ALT, // Alt key is down
        KMOD_META
    };
}

#endif //EGLE_KEYMOD_H
