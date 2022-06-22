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

  void Window::setupImGui()
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    // ImGuiIO &io = ImGui::GetIO();
    // (void)io;

    ImGui_ImplOpenGL3_Init("#version 330");
  }

  void Window::closeImGui()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
  }
} // namespace Ore
