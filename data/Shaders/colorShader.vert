#version 330 core

// args
layout (location = 0) in vec3 position;
layout (location = 3) in vec3 color;

// return
out vec3 outColor;

// uniforms: MVP (constant for shader)
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    outColor = color;

    gl_Position = projection * view * model * vec4(position, 1.0);
}