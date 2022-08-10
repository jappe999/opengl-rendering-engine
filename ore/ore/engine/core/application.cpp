#include "ore/engine/core/application.hpp"
#include "ore/engine/core/scene_loader.hpp"
#include "ore/engine/graphics/hardware_interfaces/graphics_context.hpp"
#include "ore/engine/graphics/renderers/render_graph.hpp"
#include "ore/engine/core/input.hpp"

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
    Graphics::GraphicsContext::setRenderAPI(static_cast<Graphics::RenderAPI>(Graphics::RenderAPI::OpenGL));

    window = Window::create(title, width, height);

    if (!window->createContext())
      return false;

    window->setEventCallback(RE_BIND_EVENT_FN(Application::onEvent));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glEnable(GL_MULTISAMPLE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    m_imGuiManager = new ImGuiManager();
    m_renderGraph = new Graphics::RenderGraph(window->getWidth(), window->getHeight());

    return true;
  }

  void Application::start()
  {
    // User should not be able to start the application a second time.
    if (hasStarted)
      return;

    hasStarted = true;

    m_imGuiManager->onStart();
    window->setupImGui();
    onStart();

    for (auto node : nodes)
      node->onStart();

    /* Loop until the user closes the window */
    while (onFrame())
    {
    }

    destroy();
  }

  void Application::destroy()
  {
    unloadCurrentScene();
    // Close ImGUI
    // Close other systems
    onDestroy();
  }

  void Application::onEvent(Events::Event &event)
  {
    Input::get()->onEvent(event);
    m_imGuiManager->onEvent(event);

    for (auto node : nodes)
      node->onEvent(event);

    Events::EventDispatcher dispatcher(event);
    dispatcher.dispatch<Events::WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));
    dispatcher.dispatch<Events::WindowCloseEvent>(RE_BIND_EVENT_FN(onWindowClose));
  }

  bool Application::onWindowResize(Events::WindowResizeEvent &event)
  {
    render();

    return true;
  }

  bool Application::onWindowClose(Events::WindowCloseEvent &event)
  {
    m_appState = AppState::Closing;
    return true;
  }

  bool Application::onFrame()
  {
    window->processInput();

    m_imGuiManager->onUpdate();
    render();

    return m_appState != AppState::Closing;
  }

  void Application::render()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float time = (float)glfwGetTime();
    deltaTime = time - lastFrameTime;
    lastFrameTime = time;

    for (auto node : nodes)
      node->onUpdate();

    for (auto node : nodes)
      node->onImGUI();

    for (auto node : nodes)
      node->render(camera);

    m_imGuiManager->render(camera);
    window->onUpdate();
  }
} // namespace Ore