#pragma once

#include <glm/glm.hpp>

namespace Ore
{
  class Input
  {
  public:
    static bool isKeyPressed(int32_t key);
    static bool isMouseButtonPressed(int32_t button);
    static glm::vec2 getCursorPosition();
  };
} // namespace Ore