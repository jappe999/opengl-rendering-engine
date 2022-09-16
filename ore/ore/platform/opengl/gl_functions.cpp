#include "gl_functions.hpp"
#include "gl_renderer.hpp"
#include "gl_context.hpp"
#include "gl_imgui_renderer.hpp"
#include "gl_framebuffer.hpp"
#include "gl_texture.hpp"

namespace Ore::Graphics::GL
{
  void makeDefault()
  {
    Ore::Graphics::OpenGLContext::makeDefault();
    Ore::Graphics::OpenGLRenderer::makeDefault();
    Ore::Graphics::OpenGLImGuiRenderer::makeDefault();
    Ore::Graphics::OpenGLFramebuffer::makeDefault();
    Ore::Graphics::OpenGLTexture::makeDefault();
  }
}
