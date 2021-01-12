//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Shaders/ShaderTools.h"
#include "../../include/Core/Debug.h"

#include <glad.h>

#include <fstream>

namespace eGLE
{
    void checkError(int shader, int flag, const char *msg)
    {
        GLint status;
        glGetShaderiv(shader, flag, &status); // Gets parameter of shader

        if (!status) {
            GLchar error[1024];
            glGetShaderInfoLog(shader, 1024, nullptr, error); // shader, maxLength, length (to return if needs), log

            Debug::msg("[Shader] ", msg, error);
            Debug::halt("[Shader] Halt! Shader fatal error");
        }
    }

    std::string loadShaderFile(const char *filename)
    {
        // Open File
        std::string filepath("Engine/Shaders/");
        filepath += filename;

        std::fstream file(filepath);

        // Get output
        std::string shaderText, line;

        if (!file.is_open())
            Debug::halt("[Shader] Couldn't open shader file.");

        while (file.good()) {
            std::getline(file, line);
            shaderText.append(line + "\n");
        }

        return shaderText;
    }
}