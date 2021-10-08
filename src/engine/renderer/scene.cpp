#include <iostream>
#include <engine/renderer/scene.hpp>
#include <engine/renderer/shader.hpp>
#include <engine/renderer/renderable.hpp>

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
  nodes.clear();
}