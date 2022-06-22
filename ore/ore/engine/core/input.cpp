#include "ore/engine/core/input.hpp"
#include "ore/engine/core/application.hpp"

namespace Ore
{
  Input *Input::s_instance = nullptr;
  bool Input::m_keyPressed[MAX_KEYS];
  bool Input::m_mousePressed[MAX_BUTTONS];
  glm::vec2 Input::m_mousePosition;

  bool Input::isKeyPressed(int32_t key)
  {
    return Input::m_keyPressed[key];
  }

  bool Input::isMouseButtonPressed(int32_t button)
  {
    return Input::m_mousePressed[button];
  }

  glm::vec2 Input::getCursorPosition()
  {
    return Input::m_mousePosition;
  }

  bool Input::onKeyPress(Events::KeyPressEvent &event)
  {
    Input::m_keyPressed[event.getKey()] = true;
    return true;
  }

  bool Input::onKeyRepeat(Events::KeyRepeatEvent &event)
  {
    Input::m_keyPressed[event.getKey()] = true;
    return true;
  }

  bool Input::onKeyRelease(Events::KeyReleaseEvent &event)
  {
    Input::m_keyPressed[event.getKey()] = false;
    return true;
  }

  bool Input::onKeyChar(Events::KeyCharEvent &event)
  {
    Input::m_keyPressed[event.getKeyCode()] = true;
    return true;
  }

  bool Input::onMouseMove(Events::MouseMoveEvent &event)
  {
    Input::m_mousePosition = {(float)event.getX(), (float)event.getY()};
    return true;
  }

  bool Input::onMousePress(Events::MousePressEvent &event)
  {
    Input::m_mousePressed[event.getButton()] = true;
    return true;
  }

  bool Input::onMouseRelease(Events::MouseReleaseEvent &event)
  {
    Input::m_mousePressed[event.getButton()] = false;
    return true;
  }
} // namespace Ore
