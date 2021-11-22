#pragma once

#include <memory>
#include <ore/libs/glad/glad.h>
#include "ore/engine/renderer/shader.hpp"
#include "ore/engine/renderer/world_node.hpp"
#include "ore/engine/renderer/camera.hpp"

using namespace glm;

class Renderable : public WorldNode
{
public:
  Renderable(WorldNode *parent = nullptr) : WorldNode(parent) {}
  ~Renderable() = default;

  virtual void useShader(Shader *shader);

  virtual void bind();
  virtual void render(Camera *camera);

protected:
  GLuint vao;

  Shader *shader;

  mat4 model = mat4(1.0f);

  GLuint uniform_model,
      uniform_view,
      uniform_proj;
};