#include "gl_imgui_renderer.hpp"
#include "ore/engine/events/window.hpp"
#include "imgui_impl_opengl3.h"

namespace Ore
{
  namespace Graphics
  {
    OpenGLImGuiRenderer::OpenGLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen)
    {
      ImGui_ImplOpenGL3_Init("#version 410");
      ImGui_ImplOpenGL3_NewFrame();
    }

    OpenGLImGuiRenderer::~OpenGLImGuiRenderer()
    {
      ImGui_ImplOpenGL3_Shutdown();
    }

    void OpenGLImGuiRenderer::makeDefault()
    {
      createFunc = createFuncGL;
    }

    void OpenGLImGuiRenderer::render(Camera *camera)
    {
      ImGui::Render();
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    ImGuiRenderer *OpenGLImGuiRenderer::createFuncGL(uint32_t width, uint32_t height, bool clearScreen)
    {
      return new OpenGLImGuiRenderer(width, height, clearScreen);
    }

    void OpenGLImGuiRenderer::onEvent(Events::Event &event)
    {
      Events::EventDispatcher dispatcher(event);
      dispatcher.dispatch<Events::WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));
    }

    bool OpenGLImGuiRenderer::onWindowResize(Events::WindowResizeEvent &event)
    {
      return true;
    }
  } // namespace Graphics
} // namespace Ore
