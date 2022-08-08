#version 460 core

out vec4 oColor;

uniform vec3 uColor;

void main(void) 
{
	oColor = vec4(uColor, 1.0);
}