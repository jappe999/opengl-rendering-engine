#include "texture.hpp"

namespace Ore
{
  namespace Graphics
  {
    Texture *(*Texture::createFunc)(TextureArgs) = nullptr;

    Texture *Texture::create(TextureArgs args)
    {
      return createFunc(args);
    }
  } // namespace Graphics

} // namespace Ore
