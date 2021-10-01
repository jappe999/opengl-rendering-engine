#include <iostream>
#include <engine/renderer/scene.hpp>
#include <engine/renderer/shader.hpp>

void Scene::addObject(Renderable *object)
{
  objects.emplace_back(std::move(object));
}

std::vector<Renderable *> Scene::getObjects() const
{
  return objects;
}

void Scene::render(Camera *camera)
{
  for (auto &object : objects)
    object->render(camera);
}

Scene::Scene()
{
}

Scene::~Scene()
{
  objects.clear();
}