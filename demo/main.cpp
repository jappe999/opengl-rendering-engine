#include <memory>
#include <iostream>
#include <ore/engine/core/application.hpp>
#include "cube.hpp"
#include "camera_controller.hpp"
#include "cube_controller.hpp"

class MyApp : public Ore::Application
{
public:
  void onStart() override
  {
    loadScene("assets/scenes/empty-void-with-cube.yml");
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