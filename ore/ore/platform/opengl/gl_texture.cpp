#include "gl_texture.hpp"

namespace Ore
{
  namespace Graphics
  {
    OpenGLTexture::OpenGLTexture(TextureArgs args)
    {
      m_handle = loadTexture(nullptr);
    }

    int32_t OpenGLTexture::getHandle()
    {
      return m_handle;
    }

    int32_t OpenGLTexture::loadTexture(void *data) const
    {
      uint32_t handle;

      glGenTextures(1, &handle);
      glBindTexture(GL_TEXTURE_2D, handle);

      return handle;
    }

    void OpenGLTexture::makeDefault()
    {
      createFunc = createFunctionGL;
    }

    Texture *OpenGLTexture::createFunctionGL(TextureArgs args)
    {
      return new OpenGLTexture(args);
    }
  } // namespace Graphics
} // namespace Ore
