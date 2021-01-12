//
// Created by erhoof on 12.01.2021.
//

#ifndef EGLE_SHADER_H
#define EGLE_SHADER_H

#include <vector>
#include <map>
#include <string>

#include "../Bites/Transform.h"

namespace eGLE
{
    class Texture;
    class Model;
    class RenderSystem;

    class Shader {
    public:
        Shader();
        virtual ~Shader();

        // OpenGL binding
        void enable() const;
        void disable();

        // Core Preparing
        void loadProgram(const char *text, int type);
        void compile();

        // Loading Shaders (text / file)
        void loadVertexShader   (const char *text);
        void loadFragmentShader (const char *text);
        void loadGeometryShader (const char *text);

        void loadVertexShaderFile   (const char *filename);
        void loadFragmentShaderFile (const char *filename);
        void loadGeometryShaderFile (const char *filename);

        // -- Uniforms --
        void setAttribLocation(const char *name, int location) const;
        void createUniform(const char *name);
        void setUniform(const char *name, int value);
        void setUniform(const char *name, float value);
        void setUniform(const char *name, const glm::vec3& value);
        void setUniform(const char *name, const glm::mat4& value);

        // Virtual methods
        virtual void updateUniform(Texture *texture) {};
        virtual void updateUniform(Transform &transform, Texture *texture) {};
        virtual void updateUniform(Transform &transform, Model &model, RenderSystem *rs) {};

    private:
        uint32_t m_programID;
        std::map<std::string, int> m_uniforms;
        std::vector<int> m_shaders;
    };
}

#endif //EGLE_SHADER_H
