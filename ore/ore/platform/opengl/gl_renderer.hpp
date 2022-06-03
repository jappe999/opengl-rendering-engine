#pragma once

#include "ore/engine/graphics/hardware_interfaces/render_api.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLRenderer : public RenderAPI
    {
    public:
      static void makeDefault();

    protected:
      static RenderAPI *createFunctionGL();
    };
  }
}