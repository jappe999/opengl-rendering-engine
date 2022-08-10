#include "editor.hpp"

namespace Rock
{
  void Editor::onImGUI()
  {
    // Render top bar.
    if (ImGui::BeginMainMenuBar()) {
      ImGui::EndMainMenuBar();
    }

    startDock();

    // Render all decendants.
    Node::onImGUI();
  }

  void Editor::initComponents()
  {
    SceneManager *sceneManager = new SceneManager();
    sceneManager->name = "Scene manager";
    addChild(sceneManager);
  }

  void Editor::startDock()
  {

  }
} // namespace Rock
