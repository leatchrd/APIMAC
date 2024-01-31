#include "glm/glm.hpp"
#include "p6/p6.h"

struct Vertex2DColor {
    glm::vec2 position;
    glm::vec3 color;
};

int main()
{
    auto ctx = p6::Context{{1280, 720, "TP3 EX4"}};
    ctx.maximize_window();

    const p6::Shader shader = p6::load_shader(
        "shaders/triangle.vs.glsl",
        "shaders/triangle.fs.glsl"
    );

    // Création du VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    // GLuint vbos[16];
    // glGenBuffers(16, vbos);

    // Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Remplir le VBO
    Vertex2DColor vertices[] = {
        Vertex2DColor{{-0.5f, -0.5f}, {1.f, 0.f, 0.f}},
        Vertex2DColor{{-0.5f, 0.5f}, {0.f, 1.f, 0.f}},
        Vertex2DColor{{0.5f, 0.5f}, {0.f, 0.f, 1.f}},
        Vertex2DColor{{0.5f, 0.5f}, {0.f, 0.f, 1.f}},
        Vertex2DColor{{0.5f, -0.5f}, {0.f, 0.f, 0.f}},
        Vertex2DColor{{-0.5f, -0.5f}, {1.f, 0.f, 0.f}}
    };

    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

    // Débinder le VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Création du VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    // Binding du VAO
    glBindVertexArray(vao);

    // Activation des attributs de vertex
    static constexpr GLuint aVertexPosition = 3;
    glEnableVertexAttribArray(aVertexPosition);

    static constexpr GLuint aVertexColor = 8;
    glEnableVertexAttribArray(aVertexColor);

    // Spécification des attributs de vertex
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(aVertexPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(offsetof(Vertex2DColor, position)));

    glVertexAttribPointer(aVertexColor, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(offsetof(Vertex2DColor, color)));

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

        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Débinding du VAO
        glBindVertexArray(0);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}