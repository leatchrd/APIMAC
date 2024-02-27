#include "p6/p6.h"

int main()
{
    auto ctx = p6::Context{{1280, 720, "TP4 EX2"}};
    ctx.maximize_window();

    const p6::Shader shader = p6::load_shader(
        "shaders/grey2D.vs.glsl",
        "shaders/grey2D.fs.glsl"
    );

    // Création du VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    // GLuint vbos[16];
    // glGenBuffers(16, vbos);

    // Binding du VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Remplir le VBO
    GLfloat vertices[] = {
        -0.5f, -0.5f, 1.f, 0.f, 0.f,
        0.5f, -0.5f, 0.f, 1.f, 0.f,
        0.0f, 0.5f, 0.f, 0.f, 1.f
    };
    glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    // Débinder le VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Création du VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    // Binding du VAO
    glBindVertexArray(vao);

    // Activation des attributs de vertex
    static constexpr GLuint aVertexPosition = 0;
    glEnableVertexAttribArray(aVertexPosition);

    static constexpr GLuint aVertexColor = 1;
    glEnableVertexAttribArray(aVertexColor);

    // Spécification des attributs de vertex
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glVertexAttribPointer(aVertexPosition, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));

    glVertexAttribPointer(aVertexColor, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)(2 * sizeof(GLfloat)));

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
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Débinding du VAO
        glBindVertexArray(0);
    };

    // Should be done last. It starts the infinite loop.
    ctx.start();

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

// Avancement : https://julesfouchy.github.io/Learn--OpenGL/TP4/jouer-avec-les-shaders
// On est arrivé jusqu'à "Soit P=(x,y)P=(x,y) un point et MM une matrice de transformation 3x3." dans la partie Transformation !
// On travaille dans le fichier grey2D.vs.glsl