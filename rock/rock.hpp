#include <iostream>
#include <ore/engine.hpp>
#include "ui/scenes/scene_manager.hpp"

namespace Rock
{
  class RockEditor : public Ore::Application
  {
  public:
    RockEditor() : Ore::Application("Rock Editor - Ore") {}

    void onStart() override
    {
      loadScene("assets/scenes/empty.yml");
      SceneManager *sceneManager = new SceneManager();
      sceneManager->name = "Scene manager";
      addNode(sceneManager);
      cout << "Starting Rock editor!" << endl;
    }

    void onDestroy() override
    {
      cout << "See you soon!" << endl;
    }
  };
} // namespace Ore
