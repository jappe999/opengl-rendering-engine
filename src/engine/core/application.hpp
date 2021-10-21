#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <engine/renderer/scene.hpp>
#include <engine/core/window.hpp>

class Application
{
public:
  std::string title = "OpenGL Rendering Engine";

  Application() { instance = this; }
  ~Application() {}

  static Application &getInstance() { return *instance; }
  Window &getWindow() { return *window; }
  float getDeltaTime() { return deltaTime; }

  void loadScene(std::string path);

  virtual void onStart() {}
  virtual void onDestroy() {}

  bool create(int32_t width, int32_t height, bool fullScreen = false);
  void start();
  void destroy();

protected:
  int32_t width, height;
  bool fullScreen;

  Window *window;
  Scene *scene;
  Camera *camera;

private:
  void onEvent(Event &event);

  bool hasStarted = false;

  float lastFrameTime, deltaTime;

  static Application *instance;
};