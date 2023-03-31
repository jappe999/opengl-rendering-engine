#pragma once

#include "ore/engine/graphics/hardware_interfaces/renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLRenderer : public Renderer
    {
    public:
      void internalInit() override;
      void clear() override;
      void onResize(Events::WindowResizeEvent &event) override;
      static void makeDefault();

    protected:
      static Renderer *createFunctionGL();
    };
  }
}