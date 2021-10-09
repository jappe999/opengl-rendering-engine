#include <engine/core/input.hpp>
#include <engine/core/application.hpp>

bool Input::isKeyPressed(int32_t key)
{
  GLFWwindow *window = Application::getInstance().getWindow().getNative();
  auto state = glfwGetKey(window, key);
  return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::isMouseButtonPressed(int32_t button)
{
  GLFWwindow *window = Application::getInstance().getWindow().getNative();
  auto state = glfwGetMouseButton(window, button);
  return state == GLFW_PRESS;
}

glm::vec2 Input::getCursorPosition()
{
  GLFWwindow *window = Application::getInstance().getWindow().getNative();
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);

  return {(float)xpos, (float)ypos};
}