#pragma once

#include <vector>
#include "gl.hpp"
#include "ore/engine/graphics/hardware_interfaces/framebuffer.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLFramebuffer : public Framebuffer
    {
    public:
      OpenGLFramebuffer(FramebufferArgs args);

      void bind(uint32_t width, uint32_t height) const override;
      void bind() const override;
      void unbind() const override;
      void generate() override;
      bool validate() override;
      void attachTexture(Texture *texture) override;

      static void makeDefault();

    protected:
      static Framebuffer *createFunctionGL(FramebufferArgs args);

    private:
      uint32_t m_framebuffer;
      uint32_t m_width, m_height;
      bool m_offscreen;
      std::vector<GLenum> m_attachmentData;
    };
  } // namespace Graphics
} // namespace Ore
