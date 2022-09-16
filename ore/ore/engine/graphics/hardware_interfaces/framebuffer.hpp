#pragma once

#include <stdint.h>
#include "texture.hpp"

namespace Ore
{
  namespace Graphics
  {
    struct FramebufferArgs
    {
      uint32_t width;
      uint32_t height;
      bool offscreen = true;
      int32_t attachmentCount;
      Texture **attachments;
    };

    class Framebuffer
    {
    public:
      static Framebuffer *create(FramebufferArgs args);

      /**
       * Bind and resize
       */
      virtual void bind(uint32_t width, uint32_t height) const = 0;

      /**
       * Only bind
       */
      virtual void bind() const = 0;
      virtual void unbind() const = 0;
      virtual void generate() = 0;
      virtual bool validate() = 0;
      virtual void attachTexture(Texture *texture) = 0;

    protected:
      static Framebuffer *(*createFunc)(FramebufferArgs);

      FramebufferArgs args;
    };
  } // namespace Graphics
} // namespace Ore
