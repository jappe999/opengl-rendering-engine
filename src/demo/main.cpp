#include <memory>
#include <iostream>
#include <engine/core/application.hpp>
#include "cube.hpp"

class MyApp : public Application
{
public:
  void onStart() override
  {
    Renderable *cube = new Cube();
    cube->useShader(Shader::acquire("base"));
    cube->bind();
    renderer->addObject(cube);
  }

  void onDestroy() override
  {
    cout << "See you soon!" << endl;
  }
};

int main()
{
  MyApp app;

  if (app.create(480, 360))
    app.start();

  return 0;
}