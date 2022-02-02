#include "ore/engine/core/window.hpp"
#include "ore/engine/events/mouse.hpp"
#include "ore/engine/events/window.hpp"
#include "ore/engine/events/key.hpp"

namespace Ore
{
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

    GLFWmonitor *monitor = glfwGetPrimaryMonitor();

    const GLFWvidmode *mode = glfwGetVideoMode(monitor);

    window = glfwCreateWindow(mode->width, mode->height, data.title.c_str(), NULL, NULL);

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

    // TODO: Find a better place for this.
    int fWidth, fHeight;
    glfwGetFramebufferSize(window, &fWidth, &fHeight);
    data.width = fWidth;
    data.height = fHeight;
    glViewport(0, 0, fWidth, fHeight);
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

  void Window::setEventCallback(const EventCallback &callback)
  {
    data.eventCallback = callback;
  }

  void Window::setupImGui()
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // Enable Docking
    // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;   // Enable Multi-Viewport / Platform Windows
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

    ImGui_ImplGlfw_InitForOpenGL(getNative(), true);
    ImGui_ImplOpenGL3_Init("#version 330");
  }

  void Window::closeImGui()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }
} // namespace Ore
