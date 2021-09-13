#pragma once

#include <memory>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderable/renderable.hpp>

class Renderer
{
public:
  Renderer();
  ~Renderer();

  void render();
  mat4 getProjectionMatrix();

  void addObject(std::unique_ptr<Renderable> &object);

  void setAspectRatio(float ratio);
  float getAspectRatio();

private:
  std::vector<std::unique_ptr<Renderable>> objects;
  float aspect;
};