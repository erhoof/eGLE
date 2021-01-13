#version 330 core

// args
in vec3 positionOut;
in vec2 textureCoordOut;
in vec3 normalOut;

// return
out vec4 fragColor;

// uniforms: textures and light structure
struct Light {
    vec3 ambient;
    vec3 directional;
    vec3 diffuse;
};
uniform Light light;
uniform sampler2D sampler;

// Docs: http://docs.gl/sl4

void main() {
    // Prepare args
    vec3 normal = normalize(normalOut);

    // Calculate light
    vec3 ambientL = light.ambient * texture(sampler, textureCoordOut).rgb;
    vec3 directionalL = normalize(-light.directional);

    // max - return the greater of two values
    // dot - calculate the dot product of two vectors
    float diffuseDot = max(dot(normal, directionalL), 0.0);

    // vec4 texColor? ambient * texture(sampler, texureCoordOut.xy)
    // Specular reflection
    vec3 specular = vec3(0.2, 0.5, 0.2);

    // Out Result
    vec3 result = ambientL + diffuseDot;
    fragColor = vec4(result, 1.0);
}
