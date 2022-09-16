#include "gl.hpp"
#include "gl_framebuffer.hpp"

namespace Ore
{
  namespace Graphics
  {
    OpenGLFramebuffer::OpenGLFramebuffer(FramebufferArgs args)
    {
      m_width = args.width;
      m_height = args.height;
      m_offscreen = args.offscreen;

      if (m_offscreen)
      {
        generate();
        bind();
      }

      // Attach textures
      for (int32_t i = 0; i < args.attachmentCount; i++)
      {
        Texture *texture = args.attachments[i];
        attachTexture(texture);
      }

      glDrawBuffers(static_cast<GLsizei>(m_attachmentData.size()), m_attachmentData.data());

      validate();
      unbind();
    }

    void OpenGLFramebuffer::bind(uint32_t width, uint32_t height) const
    {
      glViewport(0, 0, width, height);
      bind();
    }

    void OpenGLFramebuffer::bind() const
    {
      glBindFramebuffer(GL_FRAMEBUFFER, m_offscreen ? m_framebuffer : 0);
    }

    void OpenGLFramebuffer::unbind() const
    {
      glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void OpenGLFramebuffer::generate()
    {
      glGenFramebuffers(1, &m_framebuffer);
    }

    bool OpenGLFramebuffer::validate()
    {
      return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
    }

    void OpenGLFramebuffer::attachTexture(Texture *texture)
    {
      m_attachmentData.emplace_back(GL_COLOR_ATTACHMENT0);
      glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, (GLuint)(size_t)texture->getHandle(), 0);
    }

    void OpenGLFramebuffer::makeDefault()
    {
      createFunc = createFunctionGL;
    }

    Framebuffer *OpenGLFramebuffer::createFunctionGL(FramebufferArgs args)
    {
      return new OpenGLFramebuffer(args);
    }
  } // namespace Graphics
} // namespace Ore
