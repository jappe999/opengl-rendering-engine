#include <ore/libs/glad/glad.h>
#include <ore/engine/renderer/renderable.hpp>

class Cube : public Renderable
{
public:
  Cube(WorldNode *parent = nullptr) : Renderable(parent) {}

  void bind()
  {
    Renderable::bind();

    float vertices[] = {-1.0f, 1.0f, -1.0f,
                        -1.0f, -1.0f, -1.0f,
                        1.0f, -1.0f, -1.0f,
                        1.0f, -1.0f, -1.0f,
                        1.0f, 1.0f, -1.0f,
                        -1.0f, 1.0f, -1.0f,

                        -1.0f, -1.0f, 1.0f,
                        -1.0f, -1.0f, -1.0f,
                        -1.0f, 1.0f, -1.0f,
                        -1.0f, 1.0f, -1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f, -1.0f, 1.0f,

                        1.0f, -1.0f, -1.0f,
                        1.0f, -1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, -1.0f,
                        1.0f, -1.0f, -1.0f,

                        -1.0f, -1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, -1.0f, 1.0f,
                        -1.0f, -1.0f, 1.0f,

                        -1.0f, 1.0f, -1.0f,
                        1.0f, 1.0f, -1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f, -1.0f,

                        -1.0f, -1.0f, -1.0f,
                        -1.0f, -1.0f, 1.0f,
                        1.0f, -1.0f, -1.0f,
                        1.0f, -1.0f, -1.0f,
                        -1.0f, -1.0f, 1.0f,
                        1.0f, -1.0f, 1.0f};

    glGenVertexArrays(1, &vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(glGetAttribLocation(shader->id, "position"), 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    glEnableVertexAttribArray(0);
  }

  void render(Camera *camera)
  {
    Renderable::render(camera);

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
  }
};

ORE_REGISTER_NODE(Cube, "cube");