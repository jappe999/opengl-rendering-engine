#pragma once

#include <vector>
#include <iostream>
#include <engine/events/event.hpp>
#include <engine/core/node_factory.hpp>

class Behavior;

class Node
{
public:
  Node(Node *parent = nullptr) { this->parent = parent; };
  ~Node();

  void addBehavior(Behavior *behavior);
  virtual void onUpdate();
  virtual void onEvent(Event &event);

  template <typename T>
  bool isA() { return typeid(*this) == typeid(T); }

  template <typename T>
  bool isDerivedFrom() { return dynamic_cast<T *>(this); }

  template <typename T>
  T cast() { return dynamic_cast<T>(this); }

  bool hasParent() { return parent != nullptr; }
  Node *getParent() { return parent; }

private:
  std::vector<Behavior *> behaviors;

  Node *parent;
};