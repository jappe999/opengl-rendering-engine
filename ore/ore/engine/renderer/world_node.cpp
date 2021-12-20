#include "ore/engine/renderer/world_node.hpp"
#include "ore/engine/renderer/behavior.hpp"

namespace Ore
{
  WorldNode::~WorldNode()
  {
    for (auto behavior : behaviors)
    {
      delete behavior;
      behavior = nullptr;
    }
    behaviors.clear();
  }

  void WorldNode::onUpdate()
  {
    for (auto behavior : behaviors)
      behavior->onUpdate();

    for (auto child : children)
      child->onUpdate();
  }

  void WorldNode::onEvent(Events::Event &event)
  {
    for (auto behavior : behaviors)
      behavior->onEvent(event);

    for (auto child : children)
      child->onEvent(event);
  }

  void WorldNode::addBehavior(Behavior *behavior)
  {
    behavior->setParent(this);
    behaviors.emplace_back(behavior);
    behavior->onStart();
  }

  vec3 WorldNode::getPosition()
  {
    return position;
  }

  void WorldNode::translate(vec3 translation)
  {
    position += translation;
  }

  void WorldNode::translateTo(vec3 position)
  {
    this->position = position;
  }

  void WorldNode::rotate(float angle, vec3 axes)
  {
    rotation += vec4(axes * angle, angle);
  }

  void WorldNode::rotateTo(float angle, vec3 axes)
  {
    rotation = vec4(axes * angle, angle);
  }

  void WorldNode::scale(vec3 scale)
  {
    scaling = scale;
  }

  void WorldNode::scale(float scale)
  {
    return WorldNode::scale(vec3(scale));
  }
} // namespace Ore
