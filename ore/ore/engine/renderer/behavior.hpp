#pragma once

#include "ore/engine/events/mouse.hpp"
#include "ore/engine/events/window.hpp"
#include "ore/engine/events/key.hpp"
#include "ore/engine/renderer/world_node.hpp"

namespace Ore
{
  class Behavior : public Node
  {
  public:
    Behavior() {}
    ~Behavior() = default;

    void onEvent(Events::Event &event)
    {
      Events::EventDispatcher dispatcher(event);
      dispatcher.dispatch<Events::WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));
      dispatcher.dispatch<Events::MouseMoveEvent>(RE_BIND_EVENT_FN(onMouseMove));
      dispatcher.dispatch<Events::KeyPressEvent>(RE_BIND_EVENT_FN(onKeyPress));
      dispatcher.dispatch<Events::KeyRepeatEvent>(RE_BIND_EVENT_FN(onKeyRepeat));
      dispatcher.dispatch<Events::KeyReleaseEvent>(RE_BIND_EVENT_FN(onKeyRelease));
      dispatcher.dispatch<Events::KeyCharEvent>(RE_BIND_EVENT_FN(onKeyChar));
    }
    virtual bool onWindowResize(Events::WindowResizeEvent &event) { return false; }
    virtual bool onMouseMove(Events::MouseMoveEvent &event) { return false; }
    virtual bool onKeyPress(Events::KeyPressEvent &event) { return false; }
    virtual bool onKeyRepeat(Events::KeyRepeatEvent &event) { return false; }
    virtual bool onKeyRelease(Events::KeyReleaseEvent &event) { return false; }
    virtual bool onKeyChar(Events::KeyCharEvent &event) { return false; }
  };
} // namespace Ore
