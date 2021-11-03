#include <engine/core/application.hpp>
#include <engine/core/scene_loader.hpp>

Application *Application::instance = nullptr;

void Application::loadScene(std::string path)
{
  unloadCurrentScene();
  scene = SceneLoader::deserialize(path);
  camera = scene->getMainCamera();
}

void Application::unloadCurrentScene()
{
  if (scene != nullptr)
  {
    delete scene;
    scene = nullptr;

    // Camera is removed by the scene.
    camera = nullptr;
  }
}

bool Application::create(int32_t width, int32_t height, bool fullScreen)
{
  window = new Window(title, width, height);

  if (!window->createContext())
    return false;

  window->setEventCallback(RE_BIND_EVENT_FN(Application::onEvent));

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

  glfwSwapInterval(1);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window->getNative()))
  {
    /* Poll for and process events */
    glfwPollEvents();

    glClearColor(0, 0, 0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float time = (float)glfwGetTime();
    deltaTime = time - lastFrameTime;
    lastFrameTime = time;

    scene->render(camera);

    glfwSwapBuffers(window->getNative());
  }

  destroy();

  glfwTerminate();
}

void Application::destroy()
{
  unloadCurrentScene();
  onDestroy();
}

void Application::onEvent(Event &event)
{
  auto nodes = scene->getNodes();

  for (auto &node : nodes)
    node->onEvent(event);
}