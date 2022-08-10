#pragma once

#include <iostream>
#include <string>
#include <functional>

#include "ore/engine/events/event.hpp"

namespace Ore
{
  class Window
  {
  public:
    using EventCallback = std::function<void(Events::Event &)>;

    static Window *create(std::string title, int32_t width, int32_t height);

    virtual bool createContext() { return false; }
    virtual void setupImGui() {}
    virtual void setEventCallback(const EventCallback &callback);
    virtual void processInput() {}
    virtual void onUpdate() {}

    inline int32_t getHeight() const
    {
      return data.height;
    }
    inline int32_t getWidth() const
    {
      return data.width;
    }

  protected:
    struct WindowData
    {
      std::string title;
      int32_t width, height;

      EventCallback eventCallback;
    };

    Window(std::string title, int32_t width, int32_t height);

    WindowData data;
    friend class Application;

    static Window *(*createFunc)(std::string title, int32_t width, int32_t height);
  };
} // namespace Ore
