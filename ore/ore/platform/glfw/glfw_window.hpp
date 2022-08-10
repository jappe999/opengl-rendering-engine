#include "ore/platform/opengl/gl.hpp"
#include "ore/engine/os/window.hpp"

#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"

namespace Ore
{
  class GLFWWindow : public Window
  {
  public:
    ~GLFWWindow();

    bool createContext() override;
    void setupImGui() override;
    void processInput() override;
    void onUpdate() override;

    static void makeDefault();

  protected:
    GLFWWindow(std::string title, int32_t width, int32_t height)
        : Window(title, width, height) {}

    static Window *createFuncGLFW(std::string title, int32_t width, int32_t height);

  private:
    GLFWwindow *window;
  };
}