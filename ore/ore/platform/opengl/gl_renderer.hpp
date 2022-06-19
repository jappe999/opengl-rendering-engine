#pragma once

#include "ore/engine/graphics/hardware_interfaces/renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLRenderer : public Renderer
    {
    public:
      static void makeDefault();

    protected:
      static Renderer *createFunctionGL();
    };
  }
}