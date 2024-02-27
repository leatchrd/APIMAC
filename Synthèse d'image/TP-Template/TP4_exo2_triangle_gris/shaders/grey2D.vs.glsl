#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;

void main() {
  vFragColor = aVertexColor;
  gl_Position = vec4(aVertexPosition, 0., 1.);
};

// Translation : gl_Position = vec4(aVertexPosition + 0.5, 0., 1.);
// Agrandissement : gl_Position = vec4(aVertexPosition * 1.5, 0., 1.);
// Agrandissement sur l'axe x et réduction sur l'axe y : gl_Position = vec4(aVertexPosition.x * 2, aVertexPosition.y * 0.5, 0., 1.);
// Il y a 4 paramètres mais il comprend que aVertexPosition sans précision est implicite aka aVertexPostion.x, aVertexPosition.y
