#pragma once

#include <string>
#include <ore/engine.hpp>

namespace Rock
{
  class Scene : public Ore::Node
  {
  public:
    void onImGUI() override;
  };
} // namespace Rock
