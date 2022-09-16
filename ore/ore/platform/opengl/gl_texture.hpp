#pragma once

#include "gl.hpp"
#include "ore/engine/graphics/hardware_interfaces/texture.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLTexture : public Texture
    {
    public:
      OpenGLTexture(TextureArgs args);

      int32_t getHandle() override;
      int32_t loadTexture(void *data) const;

      static void makeDefault();

    protected:
      static Texture *createFunctionGL(TextureArgs args);
    };
  } // namespace Graphics
} // namespace Ore
