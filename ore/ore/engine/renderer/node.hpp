#pragma once

#include <vector>
#include <iostream>
#include "ore/engine/events/event.hpp"
#include "ore/engine/core/node_factory.hpp"

namespace Ore
{
  class Behavior;
  class Camera;

  class Node
  {
  public:
    Node() {}
    ~Node() {}

    /**
     * @brief Callback for frame update.
     */
    virtual void onUpdate();

    /**
     * @brief Callback for event.
     *
     * @param event The triggered event.
     */
    virtual void onEvent(Events::Event &event);

    virtual void render(Camera *camera);

    template <typename T>
    bool isA() { return typeid(*this) == typeid(T); }

    template <typename T>
    bool isDerivedFrom() { return dynamic_cast<T *>(this); }

    template <typename T>
    T cast() { return dynamic_cast<T>(this); }

    bool hasParent() { return parent != nullptr; }
    Node *getParent() { return parent; }
    void setParent(Node *parent) { this->parent = parent; }

    void addChild(Node *child);
    std::vector<Node *> getChildren();

  private:
    Node *parent;
    std::vector<Node *> children;
  };
} // namespace Ore
