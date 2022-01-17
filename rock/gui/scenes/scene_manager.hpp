#pragma once

#include <ore/engine.hpp>

namespace Rock
{
  class SceneManager : public Ore::Node
  {
  public:
    std::string name = "Scene Manager";

    void onUpdate() override;

  private:
    std::string currentScene = "empty";
  };
} // namespace Rock
