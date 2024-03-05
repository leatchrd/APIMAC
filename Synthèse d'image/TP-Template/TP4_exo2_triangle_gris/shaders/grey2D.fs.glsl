#version 330 core

in vec3 vFragColor;

out vec4 fFragColor;

void main() {
  fFragColor = vec4((vFragColor.r + vFragColor.g + vFragColor.b) / 3, (vFragColor.r + vFragColor.g + vFragColor.b) / 3, (vFragColor.r + vFragColor.g + vFragColor.b) / 3, 1.);
}

// On récupère les données du vertex aka vFragColor.quelque_chose et on les envoie au fragment aka fFragColor.