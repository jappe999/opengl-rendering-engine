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

  void WorldNode::addBehavior(Behavior *behavior)
  {
    behavior->setParent(this);
    behaviors.emplace_back(behavior);
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
