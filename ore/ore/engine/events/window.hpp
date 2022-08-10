#pragma once

#include "ore/engine/events/event.hpp"

namespace Ore::Events
{
  class WindowResizeEvent : public Event
  {
  public:
    WindowResizeEvent(int32_t width, int32_t height)
    {
      this->width = width;
      this->height = height;
    }

    int32_t getWidth() { return width; }
    int32_t getHeight() { return height; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "WindowResizeEvent: " << width << ", " << height;
      return ss.str();
    }

    EVENT_CLASS_TYPE(WindowResize);

  private:
    int32_t width, height;
  };

  class WindowCloseEvent : public Event
  {
  public:
    WindowCloseEvent() {}

    std::string toString() const override
    {
      return "WindowCloseEvent";
    }

    EVENT_CLASS_TYPE(WindowClose);
  };
} // namespace Ore::Events