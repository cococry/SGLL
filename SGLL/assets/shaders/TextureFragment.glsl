#version 460 core

in vec2 vTexCoord;

out vec4 oColor;

uniform sampler2D uTexture;

uniform vec3 uColor;

void main(void) 
{
	oColor = texture2D(uTexture, vTexCoord.ts) * vec4(uColor, 1.0f);
}