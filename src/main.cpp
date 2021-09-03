#include <iostream>
#include <engine/application.hpp>
#include <engine/renderable/cube.hpp>

using namespace std;

class MyApp : public Application
{
public:
  void onStart() override
  {
    Cube *cube = new Cube();
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