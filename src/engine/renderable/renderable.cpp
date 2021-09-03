#include <engine/renderable/renderable.hpp>
#include <engine/renderer.hpp>
#include <glm/gtc/type_ptr.hpp>

void Renderable::useShader(Shader *shader)
{
  this->shader = shader;
}

void Renderable::bind()
{
  shader->use();

  // uniform_model = glGetUniformLocation(shader->id, "model");
  uniform_view = glGetUniformLocation(shader->id, "view");
  uniform_proj = glGetUniformLocation(shader->id, "projection");
}

void Renderable::render(const mat4 view)
{
  // Attach to program_id
  shader->use();

  // glUniformMatrix4fv(uniform_model, 1, GL_FALSE, value_ptr(model));
  glUniformMatrix4fv(uniform_view, 1, GL_FALSE, value_ptr(view));
  glUniformMatrix4fv(uniform_proj, 1, GL_FALSE, value_ptr(Renderer::getInstance()->getProjectionMatrix()));
}