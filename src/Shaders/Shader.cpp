//
// Created by erhoof on 12.01.2021.
//

#include "../../include/Shaders/Shader.h"
#include "../../include/Core/Debug.h"
#include "../../include/Shaders/ShaderTools.h"

#include <glad/glad.h>
#include <string>

namespace eGLE
{
    Shader::Shader()
    {
        m_programID = glCreateProgram();

        if (!m_programID)
            Debug::halt("[Shaders] Couldn't create Shader Program");
    }

    Shader::~Shader()
    {
        for (auto const &shader : m_shaders) {
            glDetachShader(m_programID, shader);
            glDeleteShader(shader);
        }

        glDeleteProgram(m_programID);
    }

    void Shader::enable() const
    {
        glUseProgram(m_programID);
    }

    void Shader::disable()
    {
        glUseProgram(0);
    }

    void Shader::loadProgram(const char *text, int type)
    {
        // OpenGL Loader :: (GLuint shader, GLsizei count, const GLchar **string, const GLint *length)

        int shader = glCreateShader(type); // 1. shader

        if (!shader)
            Debug::halt("[Shader] Couldn't create shader.");

        const GLchar *shaderText[1];
        shaderText[0] = text; // 3. Set text to OGL capable format

        GLint lengths[1];
        lengths[0] = strlen(text); // 4. Lengths

        // Load shader OpenGL way
        glShaderSource(shader, 1, shaderText, lengths);
        glCompileShader(shader);

        checkError(m_programID, GL_COMPILE_STATUS, "compiling error");

        glAttachShader(m_programID, shader);
        m_shaders.push_back(shader);
    }

    void Shader::compile()
    {
        glLinkProgram(m_programID); // Links a program object
        checkError(m_programID, GL_LINK_STATUS, "linking error");

        glValidateProgram(m_programID); // Links a program object
        checkError(m_programID, GL_VALIDATE_STATUS, "invalid shader code");
    }

    void Shader::loadVertexShader(const char *text)
    {
        loadProgram(text, GL_VERTEX_SHADER);
    }

    void Shader::loadFragmentShader(const char *text)
    {
        loadProgram(text, GL_FRAGMENT_SHADER);
    }

    void Shader::loadGeometryShader(const char *text)
    {
        loadProgram(text, GL_GEOMETRY_SHADER);
    }

    void Shader::loadVertexShaderFile(const char *filename)
    {
        loadVertexShader(loadShaderFile(filename).c_str());
    }

    void Shader::loadFragmentShaderFile(const char *filename)
    {
        loadFragmentShader(loadShaderFile(filename).c_str());
    }

    void Shader::loadGeometryShaderFile(const char *filename)
    {
        loadGeometryShader(loadShaderFile(filename).c_str());
    }

    void Shader::setAttribLocation(const char *name, int location) const
    {
        glBindAttribLocation(m_programID, location, name);
    }

    void Shader::createUniform(const char *name)
    {
        uint32_t location = glGetUniformLocation(m_programID, name);

        m_uniforms.insert(std::pair<std::string, int>(std::string(name), location));
    }

    void Shader::setUniform(const char *name, int value)
    {
        //glUniform1i(m_uniforms.at(std::string(name)), value);
        glUniform1i(glGetUniformLocation(m_programID, name), value);
    }

    void Shader::setUniform(const char *name, float value)
    {
        //glUniform1f(m_uniforms.at(std::string(name)), value);
        glUniform1f(glGetUniformLocation(m_programID, name), value);
    }

    void Shader::setUniform(const char *name, unsigned int value)
    {
        //glUniform1ui(glGetUniformLocation(m_programID, name), value);
        glUniform1i(glGetUniformLocation(m_programID, name), value);
    }

    void Shader::setUniform(const char *name, const glm::vec3 &value)
    {
        //glUniform3f(m_uniforms.at(std::string(name)), value.x, value.y, value.z);
        glUniform3f(glGetUniformLocation(m_programID, name), value.x, value.y, value.z);
    }

    void Shader::setUniform(const char *name, const glm::mat4 &value)
    {
        // location, count, transpose, value
        //glUniformMatrix4fv(m_uniforms.at(std::string(name)), 1, GL_FALSE, &(value[0][0]));
        glUniformMatrix4fv(glGetUniformLocation(m_programID, name), 1, GL_FALSE, &(value[0][0]));
    }
}