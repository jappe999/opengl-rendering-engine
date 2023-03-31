#pragma once

#include "ore/engine/renderer/node.hpp"
#include "ore/engine/graphics/hardware_interfaces/imgui_renderer.hpp"

namespace Ore
{
  class ImGuiManager : public Node
  {
  public:
    ImGuiManager();
    ~ImGuiManager();

    // Init ImGUI.
    void onStart() override;

    // Start new ImGui frame.
    void onUpdate() override;

    // Start new ImGui frame.
    void onEvent(Events::Event &event) override;

    // Render ImGui frame.
    void render() override;

  private:
    Graphics::ImGuiRenderer *m_imGuiRenderer;
  };
} // namespace Ore
