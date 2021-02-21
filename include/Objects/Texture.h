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
        Texture(const char *filename, const char *directory);
        ~Texture();

        // Use flags
        void enable() const;
        void disable() const;

        int textureID() const;
        std::string type() const;
        void setType(std::string type);
        std::string path() const;
        void setPath(std::string path);

    private:
        unsigned int m_textureID;
        unsigned char *m_data; // TODO: check void*

        // Core properties
        int m_width;
        int m_height;
        int m_channels;
        std::string m_type;
        std::string m_path;
        // Type
        GLenum m_textureTarget;

        static const Texture *m_lastEnabled;

        void loadTexture(const char *filepath);
    };
}

#endif //EGLE_TEXTURE_H
