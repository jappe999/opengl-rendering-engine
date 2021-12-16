#include <memory>
#include <iostream>
#include <ore/engine.hpp>
#include "cube.hpp"
#include "camera_controller.hpp"
#include "cube_controller.hpp"

class DerivedApplication : public Ore::Application
{
public:
  DerivedApplication() : Application("Ore demo application") {}

  void onStart() override
  {
    loadScene("assets/scenes/empty-void-with-cube.yml");
  }

  void onDestroy() override
  {
    cout << "See you soon!" << endl;
  }
};