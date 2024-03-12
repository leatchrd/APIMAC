#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec2 vPartiPosition;
out vec3 vPartiColor;

void main() {
  vPartiPosition = aVertexPosition;
  vPartiColor = aVertexColor;
  gl_Position = vec4(aVertexPosition, 0., 1.);
}