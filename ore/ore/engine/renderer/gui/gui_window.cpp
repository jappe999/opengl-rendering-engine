#include "imgui.h"
#include "ore/engine/renderer/gui/gui_window.hpp"

namespace Ore
{
  void GuiWindow::show()
  {
    open = true;
  }

  bool GuiWindow::begin(std::string name)
  {
    return ImGui::Begin(name.c_str(), &open);
  }

  void GuiWindow::end()
  {
    ImGui::End();
  }
} // namespace Ore
