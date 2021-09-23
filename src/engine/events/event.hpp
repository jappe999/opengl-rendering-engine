#include <string>
#include <sstream>

enum EventType
{
  WindowResize
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