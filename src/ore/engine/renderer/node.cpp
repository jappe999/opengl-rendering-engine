#include "ore/engine/renderer/node.hpp"
#include "ore/engine/renderer/renderable.hpp"
#include "ore/engine/renderer/behavior.hpp"

ORE_REGISTER_NODE(Node, "ore_node");

Node::~Node()
{
  for (auto behavior : behaviors)
  {
    delete behavior;
    behavior = nullptr;
  }
  behaviors.clear();
}

void Node::addBehavior(Behavior *behavior)
{
  behaviors.emplace_back(behavior);
}

void Node::onUpdate()
{
  for (auto behavior : behaviors)
    behavior->onUpdate();
}

void Node::onEvent(Event &event)
{
  for (auto behavior : behaviors)
    behavior->onEvent(event);
}