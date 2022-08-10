#include "editor.hpp"

namespace Rock
{
  void Editor::onImGUI()
  {
    // Render top bar.
    if (ImGui::BeginMainMenuBar()) {
      ImGui::EndMainMenuBar();
    }

    // Render all decendants.
    Node::onImGUI();
  }
} // namespace Rock
