#include <iostream>

class Renderer
{
public:
  Renderer(Renderer const &) = delete;
  void operator=(Renderer const &) = delete;

  static Renderer *getInstance()
  {
    static Renderer *instance;
    return instance;
  }

  void render();

private:
  Renderer();
};