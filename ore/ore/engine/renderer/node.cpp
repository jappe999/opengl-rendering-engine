#include "ore/engine/renderer/node.hpp"
#include "ore/engine/renderer/renderable.hpp"
#include "ore/engine/renderer/camera.hpp"

ORE_REGISTER_NODE(Ore::Node, "ore_node");

namespace Ore
{
  void Node::onUpdate()
  {
    for (auto child : children)
      child->onUpdate();
  }

  void Node::onEvent(Events::Event &event)
  {
    for (auto child : children)
      child->onEvent(event);
  }

  void Node::render(Camera *camera)
  {
    for (auto child : children)
      child->render(camera);
  }

  void Node::addChild(Node *child)
  {
    child->setParent(this);
    children.emplace_back(child);
  }

  std::vector<Node *> Node::getChildren()
  {
    return children;
  }
} // namespace Ore
