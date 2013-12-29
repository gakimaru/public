#version 400

in vec3 LightIntensity;
in vec4 Color;

layout (location = 0) out vec4 FragColor;

void main()
{
	FragColor = Color * vec4(LightIntensity, 1.0);
}
