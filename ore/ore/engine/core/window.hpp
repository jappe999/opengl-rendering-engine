#pragma once

#include <iostream>
#include <string>
#include <functional>
#include "ore/libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "ore/engine/events/event.hpp"

namespace Ore
{
  class Window
  {
  public:
    using EventCallback = std::function<void(Events::Event &)>;

    Window(std::string title, int32_t width, int32_t height);
    ~Window();

    GLFWwindow *getNative() { return window; }

    bool createContext();
    void setEventCallback(const EventCallback &callback);
    void setupImGui();
    void closeImGui();

  protected:
    struct WindowData
    {
      std::string title;
      int32_t width, height;

      EventCallback eventCallback;
    };

    WindowData data;
    friend class Application;

    GLFWwindow *window;
  };
} // namespace Ore
