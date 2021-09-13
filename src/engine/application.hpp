#include <memory>
#include <string>
#include <libs/glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <engine/renderer.hpp>

class Application
{
public:
  string title = "OpenGL Rendering Engine";

  Application(){};
  ~Application(){};

  virtual void onStart() {}
  virtual void onDestroy() {}

  bool create(int32_t width, int32_t height, bool fullScreen = false);
  void start();
  void destroy();

protected:
  int32_t width, height;

  GLFWwindow *window;
  std::unique_ptr<Renderer> renderer;

  bool initializeWindow(int32_t width, int32_t height, bool fullScreen = false);
};