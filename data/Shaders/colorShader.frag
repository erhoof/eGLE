#version 330 core

// args
in vec3 outColor;

// return
out vec4 FragColor;

void main() {
    FragColor = vec4(outColor, 1.0);
}
