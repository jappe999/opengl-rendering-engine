#pragma once

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include "ore/engine/renderer/node.hpp"
#include "ore/engine/renderer/camera.hpp"

namespace Ore
{
  class SceneLoader;

  class Scene
  {
  public:
    Scene();
    ~Scene();

    void render(Camera *camera);

    void addNode(Node *node);
    std::vector<Node *> getNodes() const;

    Camera *getMainCamera() { return mainCamera; }

  private:
    std::vector<Node *> nodes;
    Camera *mainCamera;

  private:
    void setMainCamera(Camera *camera) { mainCamera = camera; }
    friend class SceneLoader;
  };
} // namespace Ore