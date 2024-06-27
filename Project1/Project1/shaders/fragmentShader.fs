#version 330 core
out vec4 FragColor;
in vec3 myColor;
in vec2 texCoord;
uniform sampler2D sampler0;
uniform sampler2D sampler1;
uniform float radio;
void main()
{
	FragColor = mix(texture(sampler0, texCoord), texture(sampler1, vec2(texCoord.x * 2, -texCoord.y * 2)), radio);
}