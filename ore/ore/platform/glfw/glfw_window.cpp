#include "./glfw_window.hpp"

#include "ore/engine/events/event.hpp"
#include "ore/engine/events/key.hpp"
#include "ore/engine/events/mouse.hpp"
#include "ore/engine/events/window.hpp"

namespace Ore
{
  GLFWWindow::~GLFWWindow()
  {
  }

  bool GLFWWindow::createContext()
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

    auto windowResizeCallback = [](GLFWwindow *window, int32_t width, int32_t height)
    {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

      data.width = width;
      data.height = height;

      Events::WindowResizeEvent event(width, height);
      data.eventCallback(event);
    };

#ifdef __APPLE__
    glfwSetFramebufferSizeCallback(window, windowResizeCallback);
#else
    glfwSetWindowSizeCallback(window, windowResizeCallback);
#endif

    glfwSetCursorPosCallback(
        window,
        [](GLFWwindow *window, double x, double y)
        {
          WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);

          Events::MouseMoveEvent event(x, y);
          data.eventCallback(event);
        });

    glfwSetMouseButtonCallback(
        window,
        [](GLFWwindow *window, int button, int action, int mods)
        {
          WindowData data = *(WindowData *)glfwGetWindowUserPointer(window);

          switch (action)
          {
          case GLFW_PRESS:
          {
            Events::MousePressEvent event(button, mods);
            data.eventCallback(event);
            break;
          }
          case GLFW_RELEASE:
          {
            Events::MouseReleaseEvent event(button, mods);
            data.eventCallback(event);
            break;
          }
          }
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
            Events::KeyPressEvent event(key, mods);
            data.eventCallback(event);
            break;
          }

          case GLFW_REPEAT:
          {
            Events::KeyRepeatEvent event(key, mods);
            data.eventCallback(event);
            break;
          }

          case GLFW_RELEASE:
          {
            Events::KeyReleaseEvent event(key, mods);
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

          Events::KeyCharEvent event(keycode);
          data.eventCallback(event);
        });

    return true;
  }

  void GLFWWindow::makeDefault()
  {
    createFunc = createFuncGLFW;
  }

  Window *GLFWWindow::createFuncGLFW(std::string title, int32_t width, int32_t height)
  {
    return new GLFWWindow(title, width, height);
  }
} // namespace Ore
