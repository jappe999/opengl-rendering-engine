#include <engine/renderer/world_node.hpp>

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

void WorldNode::rotate(float degrees, vec3 axes)
{
  rotation += vec4(axes * degrees, degrees);
}

void WorldNode::rotateTo(float degrees, vec3 axes)
{
  rotation = vec4(axes * degrees, degrees);
}

void WorldNode::scale(vec3 scale)
{
  scaling = scale;
}

void WorldNode::scale(float scale)
{
  return WorldNode::scale(vec3(scale));
}