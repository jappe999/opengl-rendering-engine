#pragma once

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/renderable.hpp>
#include <engine/renderer/camera.hpp>

class Renderer
{
public:
  Renderer();
  ~Renderer();

  void render(Camera *camera);

  void addObject(Renderable *object);
  std::vector<Renderable *> getObjects() const;

private:
  std::vector<Renderable *> objects;
};