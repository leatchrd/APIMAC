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

    // Nombre de triangles
    GLuint N = 4;

    // Remplir le VBO
    Vertex2DColor vertices[] = {
        Vertex2DColor{{glm::cos(glm::pi<float>() * 0.5), glm::cos(glm::pi<float>() * 0.5)}, {1.f, 0.f, 0.f}},
        Vertex2DColor{{glm::cos(glm::pi<float>() * 0.5 * 3), glm::cos(glm::pi<float>() * 0.5 * 3)}, {0.f, 1.f, 0.f}},
        Vertex2DColor{{glm::cos(glm::pi<float>() * 0.5 * 5), glm::cos(glm::pi<float>() * 0.5 * 5)}, {0.f, 0.f, 1.f}},
        Vertex2DColor{{glm::cos(glm::pi<float>() * 0.5 * 7), glm::cos(glm::pi<float>() * 0.5 * 7)}, {0.f, 0.f, 1.f}}
    };

    // RAPPORT DE LA SITUATION : https://julesfouchy.github.io/Learn--OpenGL/TP3/dessiner-un-disque et faut trouver comment utiliser l'équation paramétrique pour pouvoir donner les positions des points des triangles permettant de construire de cercle. Ici, 4 triangles puisque N=4 (ligne 30)
    // Puis rendre "dynamique #" : glBufferData(GL_ARRAY_BUFFER, # * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW); (ligne 44)
    // Et glDrawArrays(GL_TRIANGLES, 0, #); (ligne 85)

    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW);

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
        glDrawArrays(GL_TRIANGLES, 0, 4);

        // Débinding du VAO
        glBindVertexArray(0);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}