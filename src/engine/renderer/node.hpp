#pragma once

#include <vector>
#include <engine/renderer/behavior.hpp>
#include <engine/events/event.hpp>

class Node
{
public:
  Node() = default;
  ~Node() = default;

  void addBehavior(Behavior *behavior);

  virtual void onEvent(Event &event);

  template <typename T>
  bool isA()
  {
    return typeid(*this) == typeid(T);
  }

private:
  std::vector<Behavior *> behaviors;
};