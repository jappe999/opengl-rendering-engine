#pragma once

#include <glm/glm.hpp>
#include "ore/engine/events/event.hpp"
#include "ore/engine/events/key.hpp"
#include "ore/engine/events/mouse.hpp"

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Ore
{
  class Input
  {
  public:
    static Input *get()
    {
      if (!s_instance)
        s_instance = new Input();

      return s_instance;
    }

    bool isKeyPressed(int32_t key);
    bool isMouseButtonPressed(int32_t button);
    glm::vec2 getCursorPosition();

    void onEvent(Events::Event &event)
    {
      Events::EventDispatcher dispatcher(event);
      dispatcher.dispatch<Events::MouseMoveEvent>(RE_BIND_EVENT_FN(onMouseMove));
      dispatcher.dispatch<Events::MousePressEvent>(RE_BIND_EVENT_FN(onMousePress));
      dispatcher.dispatch<Events::MouseReleaseEvent>(RE_BIND_EVENT_FN(onMouseRelease));
      dispatcher.dispatch<Events::KeyPressEvent>(RE_BIND_EVENT_FN(onKeyPress));
      dispatcher.dispatch<Events::KeyRepeatEvent>(RE_BIND_EVENT_FN(onKeyRepeat));
      dispatcher.dispatch<Events::KeyReleaseEvent>(RE_BIND_EVENT_FN(onKeyRelease));
      dispatcher.dispatch<Events::KeyCharEvent>(RE_BIND_EVENT_FN(onKeyChar));
    }

  private:
    static Input *s_instance;

    static bool m_keyPressed[MAX_KEYS];
    static bool m_mousePressed[MAX_BUTTONS];
    static glm::vec2 m_mousePosition;

    bool onKeyPress(Events::KeyPressEvent &event);
    bool onKeyRepeat(Events::KeyRepeatEvent &event);
    bool onKeyRelease(Events::KeyReleaseEvent &event);
    bool onKeyChar(Events::KeyCharEvent &event);
    bool onMouseMove(Events::MouseMoveEvent &event);
    bool onMousePress(Events::MousePressEvent &event);
    bool onMouseRelease(Events::MouseReleaseEvent &event);
  };
} // namespace Ore