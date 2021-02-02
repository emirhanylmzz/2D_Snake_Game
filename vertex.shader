#version 330 core
#emirhan
layout(location = 0) in vec4 position;

uniform mat4 u_MVP;
void main()
{
	gl_Position = u_MVP * position;
};
