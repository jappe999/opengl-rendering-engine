#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_opengl3.h"

#include "ore/engine/events/event.hpp"

namespace Ore
{
  class Window
  {
  public:
    using EventCallback = std::function<void(Events::Event &)>;

    static Window *create(std::string title, int32_t width, int32_t height);

    GLFWwindow *getNative() { return window; }

    virtual bool createContext() { return false; }
    virtual void setEventCallback(const EventCallback &callback);

    int32_t getHeight();
    int32_t getWidth();

  protected:
    struct WindowData
    {
      std::string title;
      int32_t width, height;

      EventCallback eventCallback;
    };

    Window(std::string title, int32_t width, int32_t height);

    WindowData data;
    friend class Application;

    GLFWwindow *window;

    static Window *(*createFunc)(std::string title, int32_t width, int32_t height);
  };
} // namespace Ore
