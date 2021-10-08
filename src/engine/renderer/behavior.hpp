#pragma once

#include <engine/events/mouse.hpp>
#include <engine/events/window.hpp>

class Node;

class Behavior
{
public:
  Behavior(Node *node) { this->node = node; }
  ~Behavior() {}

  void onEvent(Event &event)
  {
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<WindowResizeEvent>(RE_BIND_EVENT_FN(onWindowResize));
    dispatcher.dispatch<MouseMoveEvent>(RE_BIND_EVENT_FN(onMouseMove));
  }
  virtual bool onWindowResize(WindowResizeEvent &event) { return false; }
  virtual bool onMouseMove(MouseMoveEvent &event) { return false; }

protected:
  Node *node;
};