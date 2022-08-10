#include "imgui_renderer.hpp"
#include "imgui.h"

namespace Ore
{
  namespace Graphics
  {
    ImGuiRenderer *ImGuiRenderer::create(uint32_t width, uint32_t height, bool clearScreen)
    {
      return createFunc(width, height, clearScreen);
    }

    void ImGuiRenderer::newFrame()
    {
      ImGui::NewFrame();
    }

    ImGuiRenderer *(*ImGuiRenderer::createFunc)(uint32_t width, uint32_t height, bool clearScreen) = nullptr;
  } // namespace Graphics
} // namespace Ore
