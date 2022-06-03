#pragma once

namespace Ore
{
  namespace Graphics
  {
    enum RenderAPI
    {
      OpenGL,
      None,
    };

    class GraphicsContext
    {
    public:
      virtual ~GraphicsContext();

      static RenderAPI getRenderAPI() { return s_renderAPI; }
      static void setRenderAPI(RenderAPI api);

      static GraphicsContext *create();

    protected:
      static GraphicsContext *(*createFunction)();

      static RenderAPI s_renderAPI;
    };
  } // namespace Graphics
} // namespace Ore
