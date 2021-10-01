#pragma once

#include <string>
#include <sstream>

#define RE_BIND_EVENT_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

enum EventType
{
  WindowResize,
  MouseMove
};

/** A convience macro for getting information about the event. */
#define EVENT_CLASS_TYPE(type)                                                \
  static EventType getStaticType() { return EventType::type; }                \
  virtual EventType getEventType() const override { return getStaticType(); } \
  virtual const char *getName() const override { return #type; }

class Event
{
public:
  virtual ~Event() = default;

  bool handled;

  virtual EventType getEventType() const = 0;
  virtual const char *getName() const = 0;
  virtual std::string toString() const { return getName(); }
};

class EventDispatcher
{
public:
  EventDispatcher(Event &e) : event(e)
  {
  }

  // F will be deduced by the compiler
  template <typename T, typename F>
  bool dispatch(const F &callback)
  {
    if (event.getEventType() == T::getStaticType())
    {
      event.handled |= callback(static_cast<T &>(event));
      return true;
    }
    return false;
  }

private:
  Event &event;
};

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
