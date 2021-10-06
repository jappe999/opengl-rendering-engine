#pragma once

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/node.hpp>
#include <engine/renderer/camera.hpp>

class Scene
{
public:
  Scene();
  ~Scene();

  void render(Camera *camera);

  void addNode(Node *node);
  std::vector<Node *> getNodes() const;

private:
  std::vector<Node *> nodes;
};