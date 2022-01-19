#pragma once

#include "../gui_window.hpp"

namespace Rock
{
  class SceneManager : public GuiWindow
  {
  public:
    SceneManager() : GuiWindow("Scene Manager") {}

    void onGui() override;

  private:
    std::string currentScene = "empty";
  };
} // namespace Rock
