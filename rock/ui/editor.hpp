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
      ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
      initComponents();
    }

    void onImGUI() override;

  private:
    void initComponents()
    {
      SceneManager *sceneManager = new SceneManager();
      sceneManager->name = "Scene manager";
      addChild(sceneManager);
    }
  };
} // namespace Rock
