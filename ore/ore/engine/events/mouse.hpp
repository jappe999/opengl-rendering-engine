#pragma once

#include "ore/engine/events/event.hpp"

namespace Ore::Events
{
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

  class MousePressEvent : public Event
  {
  public:
    MousePressEvent(int _button, int _mods) : button(_button), mods(_mods) {}

    int getButton() { return button; }
    int getMods() { return mods; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "MousePressEvent: " << button << ", " << mods;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MousePress);

  private:
    int button, mods;
  };

  class MouseReleaseEvent : public Event
  {
  public:
    MouseReleaseEvent(int _button, int _mods) : button(_button), mods(_mods) {}

    int getButton() { return button; }
    int getMods() { return mods; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "MouseReleaseEvent: " << button << ", " << mods;
      return ss.str();
    }

    EVENT_CLASS_TYPE(MouseRelease);

  private:
    int button, mods;
  };
} // namespace Ore::Events
