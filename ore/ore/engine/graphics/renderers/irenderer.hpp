#pragma once

#include "ore/engine/graphics/hardware_interfaces/render_api.hpp"

namespace Ore
{
  namespace Graphics
  {
    class IRenderer
    {
    public:
      virtual ~IRenderer();

      virtual void init() = 0;
      virtual void beginScene() = 0;
      virtual void renderScene() = 0;
    };
  } // namespace Graphics
} // namespace Ore
