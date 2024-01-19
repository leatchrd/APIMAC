#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <iostream>
#include <strings.h>

using namespace glimac;

int main(int argc, char **argv) {
  // Initialize SDL and open a window
  SDLWindowManager windowManager(800, 600, "GLImac");

  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if (GLEW_OK != glewInitError) {
    std::cerr << glewGetErrorString(glewInitError) << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
  std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

  // Création du VBO
  GLuint vbo;
  glGenBuffers(1, &vbo);

  // GLuint vbos[16];
  // glGenBuffers(16, vbos);

  // Binding du VBO
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  // Remplir le VBO
  GLfloat vertices[] = {-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f};
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

  // Débinder le VBO
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Création du VAO
  GLuint vao;
  glGenVertexArrays(1, &vao);

  // Binding du VAO
  glBindVertexArray(vao);

  // Activation des attributs de vertex
  const GLuint vertex_attr_position = 0;
  glEnableVertexAttribArray(vertex_attr_position);

  // Spécification des attributs de vertex
  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glVertexAttribPointer(vertex_attr_position, 2, GL_FLOAT, GL_FALSE,
                        2 * sizeof(GLfloat), 0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Débinding du VAO
  glBindVertexArray(0);

  // Application loop:
  bool done = false;
  while (!done) {
    // Event loop:
    SDL_Event e;
    while (windowManager.pollEvent(e)) {
      if (e.type == SDL_QUIT) {
        done = true; // Leave the loop after this iteration
      }
    }

    // Dessin du triangle
    // Nettoyer la fenêtre
    glClear(GL_COLOR_BUFFER_BIT);

    // Dessiner en utilisant le VAO
    glBindVertexArray(vao);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Débinding du VAO
    glBindVertexArray(0);

    // Update the display
    windowManager.swapBuffers();
  }
  glDeleteBuffers(1, &vbo);
  glDeleteVertexArrays(1, &vao);

  return EXIT_SUCCESS;
}
