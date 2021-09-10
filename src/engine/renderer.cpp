#include <iostream>
#include <engine/renderer.hpp>
#include <engine/shader.hpp>

Renderer::Renderer()
{
}

void Renderer::addObject(Renderable *object)
{
  objects.push_back(object);
}

void Renderer::render(Camera *camera)
{
  for (auto object : objects)
    object->render(camera);
}