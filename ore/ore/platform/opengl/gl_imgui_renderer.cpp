#include "gl_imgui_renderer.hpp"
#include "ore/engine/events/window.hpp"
#include "ore/platform/opengl/gl.hpp"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

namespace Ore
{
  namespace Graphics
  {
    OpenGLImGuiRenderer::OpenGLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen)
    {
      m_clearScreen = clearScreen;
      ImGui_ImplOpenGL3_Init("#version 410");
    }

    OpenGLImGuiRenderer::~OpenGLImGuiRenderer()
    {
      ImGui_ImplOpenGL3_Shutdown();
    }

    void OpenGLImGuiRenderer::makeDefault()
    {
      createFunc = createFuncGL;
    }

    void OpenGLImGuiRenderer::newFrame()
    {
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplGlfw_NewFrame();
      ImGui::NewFrame();
    }

    void OpenGLImGuiRenderer::render()
    {
      ImGui::Render();

      // if(m_clearScreen) glClear(GL_COLOR_BUFFER_BIT);

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
      newFrame();
      return true;
    }
  } // namespace Graphics
} // namespace Ore
