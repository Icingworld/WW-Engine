// 适用于6个面不完全一致的立方体

#version 330 core

out vec4 FragColor;

in vec2 TexCoords;
in float TexLayer;

uniform sampler2DArray texture0;

void main()
{
    FragColor = texture(texture0, vec3(TexCoords, TexLayer));
}
