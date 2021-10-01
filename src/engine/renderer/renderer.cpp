#include <iostream>
#include <engine/renderer/renderer.hpp>
#include <engine/renderer/shader.hpp>

void Renderer::addObject(Renderable *object)
{
  objects.emplace_back(std::move(object));
}

std::vector<Renderable *> Renderer::getObjects() const
{
  return objects;
}

void Renderer::render(Camera *camera)
{
  for (auto &object : objects)
    object->render(camera);
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
  objects.clear();
}