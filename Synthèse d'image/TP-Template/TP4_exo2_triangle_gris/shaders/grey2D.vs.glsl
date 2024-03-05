#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;

mat3 translate(float tx, float ty) {
  mat3 T = mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
  return T;
}

mat3 scale(float sx, float sy) {
  mat3 T = mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
  return T;
}

mat3 rotate(float a) {
  mat3 R = mat3(vec3(cos(a), sin(a), 0), vec3(-sin(a), cos(a), 0), vec3(0, 0, 1));
  return R;
}

void main() {
  vFragColor = aVertexColor;
  gl_Position = vec4(aVertexPosition, 0., 1.);

// Translation : gl_Position = vec4(aVertexPosition + 0.5, 0., 1.);
// Agrandissement : gl_Position = vec4(aVertexPosition * 1.5, 0., 1.);
// Agrandissement sur l'axe x et réduction sur l'axe y : gl_Position = vec4(aVertexPosition.x * 2, aVertexPosition.y * 0.5, 0., 1.);
// Il y a 4 paramètres mais il comprend que aVertexPosition sans précision est implicite aka aVertexPostion.x, aVertexPosition.y

// Translation : gl_Position = vec4((translate(0.5, 0.5) * vec3(aVertexPosition, 1.)).xy, 0., 1.);
// Agrandissement : gl_Position = vec4((translate(0.5, 0.5) * vec3(aVertexPosition, 1.)).xy, 0., 1.);

// Rotation de 45° : gl_Position = vec4((rotate(45) * vec3(aVertexPosition, 1.)).xy, 0., 1.);

}