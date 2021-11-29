#pragma once

#include <map>
#include <string>
#include <iostream>

namespace Ore
{
  class Node;
  class WorldNode;

  struct NodeFactory
  {
  private:
    typedef Node *NodeInstantiator(WorldNode *parentNode);
    typedef std::map<std::string, NodeInstantiator *> NodeInstantiators;
    static NodeInstantiators &instantiators()
    {
      static NodeInstantiators instantiators;
      return instantiators;
    }

  public:
    static Node *create(const std::string id, WorldNode *parentNode = nullptr)
    {
      // Find the instantiator function for the id.
      const NodeInstantiators::const_iterator iterator = instantiators().find(id);

      // If the function is found, execute it to create the new Node.
      if (iterator != instantiators().end())
        return (*iterator->second)(parentNode);

      std::cout << "Cannot find instantiator function for id " << id << "." << std::endl;
      return 0;
    }

  private:
    template <class T = int>
    struct Register
    {
      static Node *create(WorldNode *parentNode = nullptr) { return new T(parentNode); }
      static NodeInstantiator *withId(const std::string id)
      {
        std::cout << id << std::endl;
        return instantiators()[id] = create;
      }
      static NodeInstantiator *instantiator;
    };
  };
} // namespace Ore

#define ORE_REGISTER_NODE(T, id) template <> \
                                 Ore::NodeFactory::NodeInstantiator *Ore::NodeFactory::Register<T>::instantiator = Ore::NodeFactory::Register<T>::withId(id);
