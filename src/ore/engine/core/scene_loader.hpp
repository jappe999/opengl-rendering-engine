#pragma once

#include <string>
#include "ore/engine/renderer/scene.hpp"
#include "ore/engine/renderer/behavior.hpp"

namespace Ore
{
  class SceneLoader
  {
  public:
    static Scene *deserialize(std::string path);
    static std::string serialize(const std::string path);
  };
} // namespace Ore
