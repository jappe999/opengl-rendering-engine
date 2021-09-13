#include <iostream>
#include <engine/renderer.hpp>
#include <engine/shader.hpp>

void Renderer::addObject(std::unique_ptr<Renderable> &object)
{
  objects.emplace_back(std::move(object));
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