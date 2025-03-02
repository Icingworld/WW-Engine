// 适用于6个面不完全一致的立方体

#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;
layout (location = 2) in float aTexLayer;

out vec2 TexCoords;
out float TexLayer;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    TexCoords = aTexCoords;
    TexLayer = aTexLayer;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}