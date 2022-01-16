#include "ore/engine/core/application.hpp"
#include "ore/engine/core/scene_loader.hpp"

namespace Ore
{
  Application *Application::instance = nullptr;

  void Application::loadScene(std::string path)
  {
    unloadCurrentScene();
    scene = SceneLoader::deserialize(path);
    camera = scene->getMainCamera();
    camera->setAspectRatio((float)window->data.width / window->data.height);

    addNode(scene);
  }

  void Application::unloadCurrentScene()
  {
    if (scene != nullptr)
    {
      removeNode(scene);

      delete scene;
      scene = nullptr;

      // Camera is removed by the scene.
      camera = nullptr;
    }
  }

  void Application::addNode(Node *node)
  {
    nodes.emplace_back(node);
  }

  void Application::removeNode(Node *node)
  {
    nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
  }

  bool Application::create(int32_t width, int32_t height, bool fullScreen)
  {
    window = new Window(title, width, height);

    if (!window->createContext())
      return false;

    window->setEventCallback(RE_BIND_EVENT_FN(Application::onEvent));
    window->setupImGui();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glEnable(GL_MULTISAMPLE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    const GLubyte *glRenderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte *glVersion = glGetString(GL_VERSION);   // version as a string
    const GLubyte *glShader = glGetString(GL_SHADING_LANGUAGE_VERSION);

    printf("Renderer: %s\n", glRenderer);
    printf("OpenGL version supported %s\n", glVersion);
    printf("Shader supported %s\n", glShader);

    return true;
  }

  void Application::start()
  {
    // User should not be able to start the application a second time.
    if (hasStarted)
      return;

    hasStarted = true;

    onStart();

    for (auto node : nodes)
      node->onStart();

    glfwSwapInterval(1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window->getNative()))
    {
      /* Poll for and process events */
      glfwPollEvents();

      render();
    }

    destroy();

    glfwTerminate();
  }

  void Application::destroy()
  {
    window->closeImGui();
    unloadCurrentScene();
    onDestroy();
  }

  void Application::onEvent(Events::Event &event)
  {
    Events::EventDispatcher dispatcher(event);
    dispatcher.dispatch<Events::WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));

    for (auto node : nodes)
      node->onEvent(event);
  }

  bool Application::onWindowResize(Events::WindowResizeEvent &event)
  {
    // Fix up the viewport to maintain aspect ratio.
    glViewport(0, 0, event.getWidth(), event.getHeight());

    render();

    return true;
  }

  void Application::render()
  {
    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    float time = (float)glfwGetTime();
    deltaTime = time - lastFrameTime;
    lastFrameTime = time;

    for (auto node : nodes)
      node->onUpdate();

    for (auto node : nodes)
      node->render(camera);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window->getNative());
  }
} // namespace Ore