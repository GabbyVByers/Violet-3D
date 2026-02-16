
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

uniform mat4 uTransformViewProject;

out vec4 vertColor;
void main() {
	gl_Position = uTransformViewProject * vec4(aPos, 1.0);
	vertColor = aColor;
}

