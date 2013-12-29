#version 400
in vec3 VertexPosition;
//in vec3 VertexColor;
in vec4 VertexColor;
out vec4 Color;

//#version 410
//#extension GL_ARB_separate_shader_objects : enable
//layout (location = 0) in vec3 VertexPosition;
//layout (location = 1) in vec3 VertexColor;
//out vec3 Color;

uniform mat4 RotationMatrix;

void main()
{
//	Color = vec4(VertexColor, 1.0);
	Color = VertexColor;
//	gl_Position = vec4(VertexPosition, 1.0);
	gl_Position = RotationMatrix * vec4(VertexPosition, 1.0);
}
