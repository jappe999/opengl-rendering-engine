#include "gl_functions.hpp"
#include "gl_renderer.hpp"
#include "gl_context.hpp"

namespace Ore::Graphics::GL
{
  void makeDefault()
  {
    Ore::Graphics::OpenGLContext::makeDefault();
    Ore::Graphics::OpenGLRenderer::makeDefault();
    Ore::Graphics::OpenGLRenderer::makeDefault();
  }
}
