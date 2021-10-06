#include <engine/renderer/node.hpp>
#include <engine/renderer/renderable.hpp>

void Node::addBehavior(Behavior *behavior)
{
  behaviors.emplace_back(behavior);
}

void Node::onEvent(Event &event)
{
  for (auto behavior : behaviors)
    behavior->onEvent(event);
}