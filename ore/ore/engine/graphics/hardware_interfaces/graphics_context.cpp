#include "graphics_context.hpp"
#include "platform/opengl/gl_functions.hpp"

namespace Ore
{
  namespace Graphics
  {

    void GraphicsContext::setRenderAPI(RenderAPI api)
    {
      s_renderAPI = api;

      switch (api)
      {
      case RenderAPI::OpenGL:
        OpenGL::makeDefault();
        break;

      default:
        break;
      }
    }

    GraphicsContext *create()
    {
      return createFunction();
    }
  } // namespace Graphics
} // namespace Ore
