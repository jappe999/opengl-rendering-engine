#pragma once

#include "gl_renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    void OpenGLRenderer::makeDefault()
    {
      createFunction = createFunctionGL;
    }

    RenderAPI *OpenGLRenderer::createFunctionGL()
    {
      return new OpenGLRenderer();
    }
  } // namespace Graphics
} // namespace Ore
