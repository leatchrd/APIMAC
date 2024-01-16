#include <GL/glew.h>
#include <glimac/SDLWindowManager.hpp>
#include <iostream>

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

  GLuint vbos[16];
  glGenBuffers(16, vbos);

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
  const GLuint VERTEX_ATTR_POSITION = 0;
  glEnableVertexAttribArray(VERTEX_ATTR_POSITION);



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

    /*********************************
     * HERE SHOULD COME THE RENDERING CODE
     *********************************/

    // Update the display
    windowManager.swapBuffers();
  }

  return EXIT_SUCCESS;
}
