// 适用于6个面一样的立方体

#version 330 core

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture0;

void main()
{
    FragColor = texture(texture0, TexCoords);
}
