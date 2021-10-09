#pragma once

#include <vector>
#include <iostream>
#include <engine/renderer/behavior.hpp>
#include <engine/events/event.hpp>

class Node
{
public:
  Node() = default;
  ~Node() = default;

  void addBehavior(Behavior *behavior);
  virtual void onUpdate();
  virtual void onEvent(Event &event);

  template <typename T>
  bool isA() { return typeid(*this) == typeid(T); }

  template <typename T>
  bool isDerivedFrom() { return dynamic_cast<T *>(this); }

private:
  std::vector<Behavior *> behaviors;
};