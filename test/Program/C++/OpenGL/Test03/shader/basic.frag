#version 400
//in vec3 Color;
in vec4 Color;
out vec4 FragColor;

//#version 410
//#extension GL_ARB_separate_shader_objects : enable
//in vec3 Color;
//layout (location = 0) out vec4 FragColor;

void main()
{
//	FragColor = vec4(Color, 1.0);
	FragColor = Color;
}
