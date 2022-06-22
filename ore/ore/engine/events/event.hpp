#pragma once

#include <string>
#include <sstream>

#define RE_BIND_EVENT_FN(fn) [this](auto &&...args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Ore::Events
{
  enum EventType
  {
    WindowResize,
    KeyPress,
    KeyRepeat,
    KeyRelease,
    KeyChar,
    MouseMove,
    MousePress,
    MouseRelease,
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
} // namespace Ore
