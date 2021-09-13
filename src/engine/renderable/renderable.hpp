#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <libs/glad/glad.h>
#include <engine/shader.hpp>

using namespace glm;

class Renderable
{
public:
  Renderable() {}
  ~Renderable() {}

  virtual void useShader(Shader *shader);

  virtual void bind();
  virtual void render(const mat4 view);

protected:
  GLuint vao;

  Shader *shader;

  mat4 model = mat4(1.0f);

  GLuint uniform_model,
      uniform_view,
      uniform_proj;
};