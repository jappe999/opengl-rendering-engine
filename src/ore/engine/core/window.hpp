#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <ore/libs/glad/glad.h>
#include <GLFW/glfw3.h>
#include "ore/engine/events/event.hpp"

class Window
{
public:
  using EventCallback = std::function<void(Event &)>;

  Window(std::string title, int32_t width, int32_t height);
  ~Window();

  GLFWwindow *getNative() { return window; }

  bool createContext();
  void setEventCallback(const EventCallback &callback);

protected:
  struct WindowData
  {
    std::string title;
    int32_t width, height;

    EventCallback eventCallback;
  };

  WindowData data;

  GLFWwindow *window;
};