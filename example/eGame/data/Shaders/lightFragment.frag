#version 330 core

// args
in vec3 outPosition;
in vec2 outTextureCoord;
in vec3 outNormal;

// return
out vec4 FragColor;

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
    vec3 normal = normalize(outNormal);

    // Calculate light
    vec3 ambientL = light.ambient * texture(sampler, outTextureCoord).rgb;
    vec3 directionalL = normalize(-light.directional);

    // max - return the greater of two values
    // dot - calculate the dot product of two vectors
    float diffuseDot = max(dot(normal, directionalL), 0.0);

    vec3 diffuse = light.diffuse * diffuseDot * texture(sampler, outTextureCoord).rgb;

    // vec4 texColor? ambient * texture(sampler, texureCoordOut.xy)
    // Specular reflection
    vec3 specular = vec3(0.2, 0.5, 0.2);

    // Out Result
    vec3 result = ambientL + diffuse;
    //fragColor = vec4(result, 1.0);
    FragColor = vec4(result, 1.0);
}
