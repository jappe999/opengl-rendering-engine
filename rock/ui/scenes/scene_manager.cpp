#include "./scene_manager.hpp"
#include <ore/engine.hpp>
#include "../../../demo/cube.hpp"
#include "../../../demo/camera_controller.hpp"
#include "../../../demo/cube_controller.hpp"

namespace Rock
{
  void SceneManager::onImGUI()
  {
    if (ImGui::Begin("Scene Manager"))
    {
      if (currentScene != "empty-void-with-cube" && ImGui::Button("Open cube scene"))
      {
        Ore::Application::getInstance().loadScene("assets/scenes/empty-void-with-cube.yml");
        currentScene = "empty-void-with-cube";
      }
      else if (currentScene != "empty" && ImGui::Button("Open empty scene"))
      {
        Ore::Application::getInstance().loadScene("assets/scenes/empty.yml");
        currentScene = "empty";
      }
    }

    ImGui::End();
  }
} // namespace Rock
