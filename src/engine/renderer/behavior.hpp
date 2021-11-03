#pragma once

#include <engine/events/mouse.hpp>
#include <engine/events/window.hpp>
#include <engine/events/key.hpp>
#include <engine/renderer/world_node.hpp>

class Behavior : public Node
{
public:
  Behavior(WorldNode *node) : Node(node), node(node) {}
  ~Behavior() = default;

  void onEvent(Event &event)
  {
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));
    dispatcher.dispatch<MouseMoveEvent>(RE_BIND_EVENT_FN(onMouseMove));
    dispatcher.dispatch<KeyPressEvent>(RE_BIND_EVENT_FN(onKeyPress));
    dispatcher.dispatch<KeyRepeatEvent>(RE_BIND_EVENT_FN(onKeyRepeat));
    dispatcher.dispatch<KeyReleaseEvent>(RE_BIND_EVENT_FN(onKeyRelease));
    dispatcher.dispatch<KeyCharEvent>(RE_BIND_EVENT_FN(onKeyChar));
  }
  virtual bool onWindowResize(WindowResizeEvent &event) { return false; }
  virtual bool onMouseMove(MouseMoveEvent &event) { return false; }
  virtual bool onKeyPress(KeyPressEvent &event) { return false; }
  virtual bool onKeyRepeat(KeyRepeatEvent &event) { return false; }
  virtual bool onKeyRelease(KeyReleaseEvent &event) { return false; }
  virtual bool onKeyChar(KeyCharEvent &event) { return false; }

protected:
  WorldNode *node;
};