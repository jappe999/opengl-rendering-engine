#include <GLFW/glfw3.h>

#include "ore/engine/os/window.hpp"
#include "ore/engine/events/mouse.hpp"
#include "ore/engine/events/window.hpp"
#include "ore/engine/events/key.hpp"

namespace Ore
{
  Window *(*Window::createFunc)(std::string title, int32_t width, int32_t height) = nullptr;

  Window::Window(std::string title, int32_t width, int32_t height)
  {
    data.title = title;
    data.width = width;
    data.height = height;
  }

  Window *Window::create(std::string title, int32_t width, int32_t height)
  {
    return createFunc(title, width, height);
  }

  void Window::setEventCallback(const EventCallback &callback)
  {
    data.eventCallback = callback;
  }
} // namespace Ore
