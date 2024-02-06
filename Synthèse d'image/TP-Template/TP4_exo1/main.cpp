#include <glm/gtc/constants.hpp>
#include "glm/glm.hpp"
#include "p6/p6.h"

struct Vertex2DColor {
    glm::vec2 position;
    glm::vec3 color;
};

int main()
{
    auto ctx = p6::Context{{1280, 720, "TP3 EX6"}};
    ctx.maximize_window();

    const p6::Shader shader = p6::load_shader(
        "shaders/triangle.vs.glsl",
        "shaders/triangle.fs.glsl"
    );

    // Création du VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    // Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Nombre de triangles
    GLuint  N     = 1500;
    GLfloat r     = 0.5;
    GLfloat theta = 2 * glm::pi<float>() / N;

    // Remplir le VBO avec les points et non plus les sommets de chaque triangle
    std::vector<Vertex2DColor> vertices;
    vertices.push_back(Vertex2DColor{{0.f, 0.f}, {0.f, 0.f, 1.f}});
    for (uint i = 0; i < N; i++)
    {
        vertices.push_back(Vertex2DColor{{r * glm::cos(i * theta), r * glm::sin(i * theta)}, {0.f, 1.f, 0.f}});
    }

    glBufferData(GL_ARRAY_BUFFER, (N + 1) * sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

    // Débinder le VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Création du IBO
    GLuint ibo;
    glGenBuffers(1, &ibo);

    // Blinding du IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // Vecteur contenant les indices des sommets à dessiner
    std::vector<uint32_t> indices;
    for (uint i = 1; i < N + 1; i++)
    {
        indices.push_back(0);
        indices.push_back(i);

        if (i == N)
        {
            indices.push_back(1);
            break;
        }

        indices.push_back(i + 1);
    }

    // Remplir le IBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * N * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

    // Debinder le IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    // Création du VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    // Binding du VAO
    glBindVertexArray(vao);

    // Binding de l'IBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    // Activation des attributs de vertex
    static constexpr GLuint aVertexPosition = 3;
    glEnableVertexAttribArray(aVertexPosition);

    static constexpr GLuint aVertexColor = 8;
    glEnableVertexAttribArray(aVertexColor);

    // Spécification des attributs de vertex
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(aVertexPosition, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, position));

    glVertexAttribPointer(aVertexColor, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2DColor), (const GLvoid*)offsetof(Vertex2DColor, color));

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
        glDrawElements(GL_TRIANGLES, 3 * N, GL_UNSIGNED_INT, 0);

        // Débinding du VAO
        glBindVertexArray(0);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
};

// Avancement : https://julesfouchy.github.io/Learn--OpenGL/TP4/les-shaders-par-l-exemple