#include "framebuffer.hpp"

namespace Ore
{
  namespace Graphics
  {
    Framebuffer *(*Framebuffer::createFunc)(FramebufferArgs) = nullptr;

    Framebuffer *Framebuffer::create(FramebufferArgs args)
    {
      return createFunc(args);
    }
  } // namespace Graphics

} // namespace Ore
