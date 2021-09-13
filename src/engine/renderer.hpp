#pragma once

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderable/renderable.hpp>
#include <engine/camera.hpp>

class Renderer
{
public:
  Renderer();
  ~Renderer();

  void render(Camera *camera);

  void addObject(std::unique_ptr<Renderable> &object);

private:
  std::vector<std::unique_ptr<Renderable>> objects;
};