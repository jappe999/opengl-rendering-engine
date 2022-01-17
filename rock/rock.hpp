#include <iostream>
#include <ore/engine.hpp>
#include "gui/dock.hpp"
namespace Rock
{
  class RockEditor : public Ore::Application
  {
  public:
    RockEditor() : Ore::Application("Rock Editor - Ore") {}

    void onStart() override
    {
      loadScene("assets/scenes/empty.yml");
      addNode(new GuiDock());
      cout << "Starting Rock editor!" << endl;
    }

    void onDestroy() override
    {
      cout << "See you soon!" << endl;
    }
  };
} // namespace Ore
