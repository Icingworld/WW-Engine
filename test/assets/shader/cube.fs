#version 330 core
in vec3 Color;
in vec2 TexCoords;
out vec4 FragColor;
uniform sampler2D Texture0;

void main()
{
    FragColor = texture(Texture0, TexCoords);
}