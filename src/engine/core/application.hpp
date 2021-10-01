#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <engine/renderer/renderer.hpp>
#include <engine/core/window.hpp>

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
  bool fullScreen;

  Window *window;
  Renderer *renderer;
  Camera *camera;

private:
  void onEvent(Event &event);

  bool hasStarted = false;
};