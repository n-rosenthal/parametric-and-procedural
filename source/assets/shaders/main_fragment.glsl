#version 333 core

in vec4 cor_interpolada;
in vec3 fragment_position;
in vec3 fragment_normal;
in vec2 fragment_texcoords;

uniform sampler2D texture_color;
uniform bool use_texture;

out vec4 color;

void main()
{
    // Directional light from top-right-front
    vec3 light_dir = normalize(vec3(1.0, 1.0, 1.0));
    vec3 normal = normalize(fragment_normal);

    // Ambient lighting
    float ambient = 0.2;

    // Diffuse lighting
    float diffuse = max(dot(normal, light_dir), 0.0) * 0.8;

    // Combined lighting factor
    float lighting = ambient + diffuse;

    // Base color
    vec4 base_color = cor_interpolada;
    if (use_texture) {
        base_color = texture(texture_color, fragment_texcoords);
    }

    color = vec4(base_color.rgb * lighting, base_color.a);
}
