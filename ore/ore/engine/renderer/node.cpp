#include "ore/engine/renderer/node.hpp"
#include "ore/engine/renderer/renderable.hpp"
#include "ore/engine/renderer/camera.hpp"

ORE_REGISTER_NODE(Ore::Node, "ore_node");

namespace Ore
{
  Node::~Node()
  {
    for (Node *child : children)
    {
      delete child;
      child = nullptr;
    }
    children.clear();
  }

  void Node::onUpdate()
  {
    for (auto child : children)
      child->onUpdate();
  }

  void Node::onGui()
  {
    for (auto child : children)
      child->onGui();
  }

  void Node::onEvent(Events::Event &event)
  {
    for (auto child : children)
      child->onEvent(event);
  }

  void Node::render(Camera *camera)
  {
    for (auto child : children)
    {
      // Validate that the child can be rendered.
      if (child->isDerivedFrom<Renderable>())
        dynamic_cast<Renderable *>(child)->render(camera);
    }
  }

  void Node::addChild(Node *child)
  {
    child->setParent(this);
    children.emplace_back(child);
    child->onStart();
  }

  std::vector<Node *> Node::getChildren()
  {
    return children;
  }
} // namespace Ore
