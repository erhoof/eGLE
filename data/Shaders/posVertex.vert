#version 330 core

// args
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textureCoord;
layout (location = 2) in vec3 normal;

// return
out vec3 outPosition;
out vec2 outTextureCoord;
out vec3 outNormal;

// uniforms: MVP (constant for shader)
uniform mat4 model;
uniform mat4 view;
uniform mat4 projecton;

void main()
{
    // to return
    outPosition = vec3(model * vec4(position, 1.0));
    outTextureCoord = textureCoord;
    outNormal = mat3(transpose(inverse(model))) * normal;

    // set (position of the current vertex) mul backwards! P*V*M
    gl_Position = projecton * view * model * vec4(position, 1.0);
}