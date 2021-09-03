#include <iostream>
#include <engine/renderer.hpp>
#include <engine/renderable/triangle.hpp>
#include <engine/shader.hpp>

Renderer::Renderer()
{
  Triangle *triangle = new Triangle();
  triangle->useShader(Shader::acquire("base"));
  triangle->bind();
  objects.push_back(triangle);
}

void Renderer::render()
{
  const vec3 cameraFront = glm::vec3(2.0f, 0.0f, 1.0f);
  const vec3 cameraPosition = glm::vec3(-5.0f, 0.0f, -5.0f);
  const vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

  const mat4 view = lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);

  for (auto object : objects)
    object->render(view);
}

void Renderer::setAspectRatio(float ratio)
{
  aspect = ratio;
}

float Renderer::getAspectRatio()
{
  return aspect;
}

mat4 Renderer::getProjectionMatrix()
{
  return perspective(radians(45.0f), aspect, 0.01f, 200.0f);
}