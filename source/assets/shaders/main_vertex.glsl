#version 333 core

layout (location = 0) in vec4 model_position;
layout (location = 1) in vec4 model_normal;
layout (location = 2) in vec2 texture_coords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 cor_interpolada;
out vec3 fragment_position;
out vec3 fragment_normal;
out vec2 fragment_texcoords;

void main()
{
    gl_Position = projection * view * model * model_position;

    fragment_position = vec3(model * model_position);
    fragment_normal = normalize(vec3(transpose(inverse(model)) * model_normal));
    fragment_texcoords = texture_coords;

    // Default color based on normal for visual debug
    cor_interpolada = vec4(fragment_normal * 0.5 + 0.5, 1.0);
}
