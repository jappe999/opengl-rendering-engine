#include "ore/platform/opengl/gl.hpp"
#include "ore/engine/os/window.hpp"

namespace Ore
{
  class GLFWWindow : public Window
  {
  public:
    ~GLFWWindow();

    bool createContext() override;

    static void makeDefault();

  protected:
    GLFWWindow(std::string title, int32_t width, int32_t height)
        : Window(title, width, height) {}

    static Window *createFuncGLFW(std::string title, int32_t width, int32_t height);
  };
}