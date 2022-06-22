#include "imgui_renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    ImGuiRenderer *(*ImGuiRenderer::createFunc)(uint32_t width, uint32_t height, bool clearScreen) = nullptr;
  } // namespace Graphics
} // namespace Ore
