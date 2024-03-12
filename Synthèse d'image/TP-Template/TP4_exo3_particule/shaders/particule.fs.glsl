#version 330 core

in vec2 vPartiPosition;
in vec3 vPartiColor;

out vec4 fPartiColor;

vec3 attenuation(vec3 Color, float alpha, float beta) {
  float distCarre = distance(vPartiPosition, vec2(0, 0)) * distance(vPartiPosition, vec2(0, 0));
  float a = alpha * exp(-beta * distCarre);
  return a * Color;
}

void main() {
  fPartiColor = vec4(attenuation(vPartiColor, 2, 50), 1.);
}