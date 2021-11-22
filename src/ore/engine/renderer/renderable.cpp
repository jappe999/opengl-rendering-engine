#include "ore/engine/renderer/renderable.hpp"
#include <glm/gtc/type_ptr.hpp>

void Renderable::useShader(Shader *shader)
{
  this->shader = shader;
}

void Renderable::bind()
{
  shader->use();

  uniform_model = glGetUniformLocation(shader->id, "model");
  uniform_view = glGetUniformLocation(shader->id, "view");
  uniform_proj = glGetUniformLocation(shader->id, "projection");
}

void Renderable::render(Camera *camera)
{
  // Attach to program_id
  shader->use();

  model = mat4(1.0f);
  model = glm::translate(model, position);
  if (rotation.w != 0.0f)
    model = glm::rotate(model, rotation.w, vec3(rotation));
  model = glm::scale(model, scaling);

  const mat4 view = camera->getViewMatrix();
  const mat4 projection = camera->getProjectionMatrix();

  glUniformMatrix4fv(uniform_model, 1, GL_FALSE, value_ptr(model));
  glUniformMatrix4fv(uniform_view, 1, GL_FALSE, value_ptr(view));
  glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, value_ptr(projection));
}