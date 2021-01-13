//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_TEXTURE_H
#define EGLE_TEXTURE_H

#include <glad.h>

namespace eGLE
{
    class Texture {
    public:
        Texture() = default;
        Texture(const char *filename);
        ~Texture();

        // Use flags
        void enable() const;
        void disable() const;

        int textureID() const;

    private:
        unsigned int m_textureID;
        unsigned char *m_data; // TODO: check void*

        // Core properties
        int m_width;
        int m_height;
        int m_channels;

        // Type
        GLenum m_textureTarget;

        static const Texture *m_lastEnabled;
    };
}

#endif //EGLE_TEXTURE_H
