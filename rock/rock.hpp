#include <iostream>
#include <ore/engine.hpp>

namespace Ore
{
  class RockEditor : public Application
  {
  public:
    RockEditor() : Application("Rock Editor - Ore") {}

    void onStart() override
    {
      loadScene("assets/scenes/empty.yml");
      cout << "Starting Rock editor!" << endl;
    }

    void onDestroy() override
    {
      cout << "See you soon!" << endl;
    }
  };
} // namespace Ore
