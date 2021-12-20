#pragma once

#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "ore/engine/renderer/scene.hpp"
#include "ore/engine/core/window.hpp"
#include "ore/engine/events/window.hpp"

namespace Ore
{
  class Application
  {
  public:
    std::string title;

    Application(std::string _title = "OpenGL Rendering Engine - Ore")
        : title(_title), scene(nullptr), camera(nullptr)
    {
      instance = this;
    }
    ~Application() {}

    static Application &getInstance() { return *instance; }
    Window &getWindow() { return *window; }
    float getDeltaTime() { return deltaTime; }

    void loadScene(std::string path);
    void unloadCurrentScene();

    void addNode(Node *node);
    void removeNode(Node *node);

    virtual void onStart() {}
    virtual void onDestroy() {}

    bool create(int32_t width, int32_t height, bool fullScreen = false);
    friend int main(int argc, char **argv);
    void start();
    friend int main(int argc, char **argv);

  protected:
    int32_t width, height;
    bool fullScreen;

    Window *window;
    Scene *scene;
    Camera *camera;

    std::vector<Node *> nodes;

  private:
    void destroy();

    void onEvent(Events::Event &event);
    bool onWindowResize(Events::WindowResizeEvent &event);
    void render();

    bool hasStarted = false;

    float lastFrameTime, deltaTime;

    static Application *instance;
  };
} // namespace Ore