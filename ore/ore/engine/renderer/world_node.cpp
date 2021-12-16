#include "ore/engine/renderer/world_node.hpp"

namespace Ore
{
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
