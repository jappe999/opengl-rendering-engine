#pragma once

#include <stdint.h>

namespace Ore
{
  namespace Graphics
  {
    struct TextureArgs
    {
      uint32_t width;
      uint32_t height;
    };

    enum class TextureType
    {
      COLOUR,
      DEPTH,
      DEPTHARRAY,
      CUBE,
      OTHER
    };

    class Texture
    {
    public:
      static Texture *create(TextureArgs args);

      virtual int32_t getHandle() = 0;

    protected:
      static Texture *(*createFunc)(TextureArgs);

      TextureArgs args;
      int32_t m_handle;
    };
  } // namespace Graphics
} // namespace Ore
