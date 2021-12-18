#include "./scene_manager.hpp"

namespace Rock
{
  void SceneManager::onUpdate()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::Begin("Hello, world!");
    ImGui::Text("Hello, world");
    ImGui::End();
  }

  void SceneManager::openScene(std::string path)
  {
    scene = Ore::SceneLoader::deserialize(path);
  }
} // namespace Rock
