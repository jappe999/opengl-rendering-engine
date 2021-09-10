#pragma once

#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderable/renderable.hpp>
#include <engine/camera.hpp>

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

  void render(Camera *camera);

  void addObject(Renderable *object);

private:
  vector<Renderable *> objects;

  Renderer();
};