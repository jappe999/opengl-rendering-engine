#pragma once

#include "ore/engine/events/event.hpp"

class MouseMoveEvent : public Event
{
public:
  MouseMoveEvent(double x, double y) : X(x), Y(y) {}

  double getX() { return X; }
  double getY() { return Y; }

  std::string toString() const override
  {
    std::stringstream ss;
    ss << "MouseMoveEvent: " << X << ", " << Y;
    return ss.str();
  }

  EVENT_CLASS_TYPE(MouseMove);

private:
  double X, Y;
};
