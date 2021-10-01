#pragma once

#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include <libs/glad/glad.h>
#include <engine/renderer/shader.hpp>
#include <engine/renderer/camera.hpp>
#include <engine/events/event.hpp>

using namespace glm;

class Renderable
{
public:
  Renderable() {}
  ~Renderable() {}

  virtual void useShader(Shader *shader);

  virtual void bind();
  virtual void render(Camera *camera);
  virtual void onEvent(Event &event);
  virtual bool onWindowResize(WindowResizeEvent &event) { return false; }
  virtual bool onMouseMove(MouseMoveEvent &event) { return false; }

protected:
  GLuint vao;

  Shader *shader;

  mat4 model = mat4(1.0f);

  GLuint uniform_model,
      uniform_view,
      uniform_proj;
};