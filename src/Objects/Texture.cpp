//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Objects/Texture.h"
#include "../../include/Core/Debug.h"

// For STB_Image
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace eGLE
{
    const Texture *Texture::m_lastEnabled = nullptr;

    Texture::Texture(const char *filename)
    {
        // Flip image fix (OGL representation)
        stbi_set_flip_vertically_on_load(true);

        // Load and verify data (file, w, h, n (8-bit components per pixel), (components per pixel in file)
        m_data = stbi_load(filename, &m_width, &m_height, &m_channels, 3);

        // If loaded
        if (m_data) {
            // ogl to gen texture name
            glGenTextures(1, &m_textureID);

            // bind to texturing target
            glBindTexture(GL_TEXTURE_2D, m_textureID);

            // define format
            GLenum type;
            switch (m_channels) {
                case 1:
                    type = GL_RED;
                    break;
                case 2:
                    type = GL_RGB;
                    break;
                case 3:
                    type = GL_RGBA;
                    break;
                default:
                    break;
            }

            // specify image: target, level (mipmap), internalFormat, width,
            // height, border (must be 0), format, type, data
            glTexImage2D(GL_TEXTURE_2D, 0, type, m_width, m_height, 0, type, GL_UNSIGNED_BYTE, m_data);

            // Setup linear filtering (https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexParameter.xhtml)
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            // Prepare mipmap (optimised seq of images)
            glGenerateMipmap(GL_TEXTURE_2D);

            stbi_image_free(m_data);

            Debug::msg("[Texture] Loaded texture from ", filename, " - ID: ", m_textureID);
        } else {
            Debug::msg("[Texture] Error loading texture ", filename, " - msg: ", stbi_failure_reason());
        }
    }

    Texture::~Texture()
    {
        // free memory after texture removal
        glDeleteTextures(1, &m_textureID);
    }

    void Texture::enable() const
    {
        // GL_TEXTURE0 means frame 0
        glActiveTexture(GL_TEXTURE0 + m_textureID);
        glBindTexture(GL_TEXTURE_2D, m_textureID);
    }

    void Texture::disable() const
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    int Texture::textureID() const
    {
        return m_textureID;
    }
}