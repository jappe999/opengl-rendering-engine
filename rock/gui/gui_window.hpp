#pragma once

#include "imgui.h"
#include <ore/engine.hpp>

namespace Rock
{
  class GuiWindow : public Ore::Node
  {
  public:
    const char *name = "GUI Window";

    GuiWindow(const char *name)
    {
      this->name = name;
    }

    virtual void onGui() {}

    void onUpdate() override
    {
      ImGui::Begin(name);

      onGui();

      Ore::Node::onUpdate();

      ImGui::End();
    }
  };
} // namespace Rock
