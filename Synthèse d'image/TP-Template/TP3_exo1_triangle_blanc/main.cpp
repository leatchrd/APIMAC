#include "glimac/default_shader.hpp"
#include "p6/p6.h"

int main()
{
    auto ctx = p6::Context{{1280, 720, "TP3 EX1"}};
    ctx.maximize_window();

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

    glVertexAttribPointer(vertex_attr_position, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Débinding du VAO
    glBindVertexArray(0);

    // Declare your infinite update loop.
    ctx.update = [&]() {
        // Dessin du triangle
        // Nettoyer la fenêtre
        glClear(GL_COLOR_BUFFER_BIT);

        // Dessiner en utilisant le VAO
        glBindVertexArray(vao);

        glimac::bind_default_shader();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Débinding du VAO
        glBindVertexArray(0);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}