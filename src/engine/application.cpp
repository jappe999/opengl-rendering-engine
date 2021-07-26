#include <iostream>
#include <engine/application.hpp>

bool Application::create(int32_t width, int32_t height, bool fullScreen)
{
  if (!initializeWindow(width, height, fullScreen))
    return false;

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glEnable(GL_BLEND);
  glEnable(GL_MULTISAMPLE);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  const GLubyte *renderer = glGetString(GL_RENDERER); // get renderer string
  const GLubyte *version = glGetString(GL_VERSION);   // version as a string
  const GLubyte *shader = glGetString(GL_SHADING_LANGUAGE_VERSION);

  printf("Renderer: %s\n", renderer);
  printf("OpenGL version supported %s\n", version);
  printf("Shader supported %s\n", shader);

  return true;
}

void Application::destroy()
{
  onDestroy();
}

bool Application::initializeWindow(int32_t width, int32_t height, bool fullScreen)
{
  if (!glfwInit())
    return false;

  window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

  if (!window)
  {
    glfwTerminate();
    return false;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    cout << "Failed to initialize OpenGL context" << endl;
    return false;
  }

  return true;
}

void Application::start()
{
  onStart();

  glfwSwapInterval(1);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Poll for and process events */
    glfwPollEvents();

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  glfwTerminate();

  destroy();
}