#include <ore/engine.hpp>
#include "scenes/scene_manager.hpp"
#include "imgui.h"

namespace Rock
{
  class Editor : public Ore::Node
  {
  public:
    Editor()
    {
      initComponents();
    }

    void onImGUI() override;

  private:
    void initComponents();
    void startDock();
  };
} // namespace Rock
