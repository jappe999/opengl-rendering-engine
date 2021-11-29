#include <engine/core/window.hpp>
#include <engine/events/mouse.hpp>
#include <engine/events/window.hpp>
#include <engine/events/key.hpp>

Window::Window(std::string title, int32_t width, int32_t height)
{
  data.title = title;
  data.width = width;
  data.height = height;
}

Window::~Window()
{
}

bool Window::createContext()
{
  if (!glfwInit())
    return false;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(data.width, data.height, data.title.c_str(), NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return false;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  glfwSetWindowUserPointer(window, &data);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize OpenGL context" << std::endl;
    return false;
  }

  // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

  glfwSetFramebufferSizeCallback(
      window,
      [](GLFWwindow *window, int32_t width, int32_t height)
      {
        WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);
        data.width = width;
        data.height = height;

        WindowResizeEvent event(width, height);
        data.eventCallback(event);
      });

  glfwSetCursorPosCallback(
      window,
      [](GLFWwindow *window, double x, double y)
      {
        WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);

        MouseMoveEvent event(x, y);
        data.eventCallback(event);
      });

  glfwSetKeyCallback(
      window,
      [](GLFWwindow *window, int key, int scancode, int action, int mods)
      {
        WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);

        switch (action)
        {
        case GLFW_PRESS:
        {
          KeyPressEvent event(key, mods);
          data.eventCallback(event);
          break;
        }

        case GLFW_REPEAT:
        {
          KeyRepeatEvent event(key, mods);
          data.eventCallback(event);
          break;
        }

        case GLFW_RELEASE:
        {
          KeyReleaseEvent event(key, mods);
          data.eventCallback(event);
          break;
        }
        }
      });

  glfwSetCharCallback(
      window,
      [](GLFWwindow *window, unsigned int keycode)
      {
        WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);

        KeyCharEvent event(keycode);
        data.eventCallback(event);
      });

  return true;
}

void Window::setEventCallback(const EventCallback &callback)
{
  data.eventCallback = callback;
}