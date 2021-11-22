#include <iostream>
#include "ore/engine/renderer/scene.hpp"
#include "ore/engine/renderer/shader.hpp"
#include "ore/engine/renderer/renderable.hpp"

void Scene::addNode(Node *node)
{
  nodes.emplace_back(std::move(node));
}

std::vector<Node *> Scene::getNodes() const
{
  return nodes;
}

void Scene::render(Camera *camera)
{
  for (auto node : nodes)
  {
    node->onUpdate();

    // Validate that the node can be rendered.
    if (node->isDerivedFrom<Renderable>())
      dynamic_cast<Renderable *>(node)->render(camera);
  }
}

Scene::Scene()
{
}

Scene::~Scene()
{
  for (auto node : nodes)
  {
    delete node;
    node = nullptr;
  }
  nodes.clear();
}