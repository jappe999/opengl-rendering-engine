#pragma once

#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderable/renderable.hpp>

using namespace std;

class Renderer
{
public:
  Renderer(Renderer const &) = delete;
  void operator=(Renderer const &) = delete;

  static Renderer *getInstance()
  {
    static Renderer *instance;

    if (instance == nullptr)
      instance = new Renderer();

    return instance;
  }

  void render();
  mat4 getProjectionMatrix();

  void setAspectRatio(float ratio);
  float getAspectRatio();

private:
  vector<Renderable *> objects;
  float aspect;

  Renderer();
};