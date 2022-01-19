#pragma once

#include <GLFW/glfw3.h>
#include "../gui_window.hpp"

namespace Rock
{
  class SceneView : public GuiWindow
  {
  public:
    SceneView() : GuiWindow("Scene View") {}
  };
} // namespace Rock
