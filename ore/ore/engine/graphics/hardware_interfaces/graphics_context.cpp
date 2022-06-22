#include "graphics_context.hpp"
#include "ore/platform/opengl/gl_functions.hpp"

namespace Ore
{
  namespace Graphics
  {
    GraphicsContext *(*GraphicsContext::createFunction)() = nullptr;

    RenderAPI GraphicsContext::s_renderAPI = RenderAPI::None;

    void GraphicsContext::setRenderAPI(RenderAPI api)
    {
      s_renderAPI = api;

      switch (api)
      {
      case RenderAPI::OpenGL:
        GL::makeDefault();
        break;

      default:
        break;
      }
    }

    GraphicsContext *GraphicsContext::create()
    {
      return createFunction();
    }
  } // namespace Graphics
} // namespace Ore
