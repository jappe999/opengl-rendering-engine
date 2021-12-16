#pragma once

#include "ore/engine/events/event.hpp"

namespace Ore::Events
{
  class KeyPressEvent : public Event
  {
  public:
    KeyPressEvent(int32_t key, int8_t mods)
    {
      this->key = key;
      this->mods = mods;
    }

    int32_t getKey() { return key; }
    int8_t getMods() { return mods; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyPressEvent: " << key << ", " << mods;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyPress);

  private:
    int32_t key;
    int8_t mods;
  };

  class KeyRepeatEvent : public Event
  {
  public:
    KeyRepeatEvent(int32_t key, int8_t mods)
    {
      this->key = key;
      this->mods = mods;
    }

    int32_t getKey() { return key; }
    int8_t getMods() { return mods; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyRepeatEvent: " << key << ", " << mods;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyRepeat);

  private:
    int32_t key;
    int8_t mods;
  };

  class KeyReleaseEvent : public Event
  {
  public:
    KeyReleaseEvent(int32_t key, int8_t mods)
    {
      this->key = key;
      this->mods = mods;
    }

    int32_t getKey() { return key; }
    int8_t getMods() { return mods; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyReleaseEvent: " << key << ", " << mods;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyRelease);

  private:
    int32_t key;
    int8_t mods;
  };

  class KeyCharEvent : public Event
  {
  public:
    KeyCharEvent(uint32_t keycode) : code(keycode) {}

    int32_t getKeyCode() { return code; }

    std::string toString() const override
    {
      std::stringstream ss;
      ss << "KeyCharEvent: " << code;
      return ss.str();
    }

    EVENT_CLASS_TYPE(KeyChar);

  private:
    uint32_t code;
  };
} // namespace Ore::Events
