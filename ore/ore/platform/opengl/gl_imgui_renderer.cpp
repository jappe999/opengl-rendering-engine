#include "gl_imgui_renderer.hpp"

#include "imgui_impl_opengl3.h"

namespace Ore
{
  namespace Graphics
  {
    OpenGLImGuiRenderer::OpenGLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen)
    {
      ImGui_ImplOpenGL3_NewFrame();
      ImGui::NewFrame();
    }

    OpenGLImGuiRenderer::~OpenGLImGuiRenderer()
    {
      ImGui_ImplOpenGL3_Shutdown();
    }

    void OpenGLImGuiRenderer::makeDefault()
    {
      createFunc = createFuncGL;
    }

    void OpenGLImGuiRenderer::render()
    {
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    ImGuiRenderer *OpenGLImGuiRenderer::createFuncGL(uint32_t width, uint32_t height, bool clearScreen)
    {
      return new OpenGLImGuiRenderer(width, height, clearScreen);
    }
  } // namespace Graphics
} // namespace Ore
