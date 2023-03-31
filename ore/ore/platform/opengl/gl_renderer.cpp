#include "gl_renderer.hpp"
#include "gl.hpp"

namespace Ore
{
  namespace Graphics
  {
    void OpenGLRenderer::internalInit()
    {
    }

    void OpenGLRenderer::clear()
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderer::onResize(Events::WindowResizeEvent &event)
    {
      // Fix up the viewport to maintain aspect ratio.
      glViewport(0, 0, event.getWidth(), event.getHeight());
    }

    void OpenGLRenderer::makeDefault()
    {
      createFunction = createFunctionGL;
    }

    Renderer *OpenGLRenderer::createFunctionGL()
    {
      return new OpenGLRenderer();
    }
  } // namespace Graphics
} // namespace Ore
