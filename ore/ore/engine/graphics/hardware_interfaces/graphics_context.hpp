#pragma once

namespace Ore
{
  namespace Graphics
  {
    /**
     * List of available render APIs.
     */
    enum RenderAPI
    {
      OpenGL,
      None,
    };

    /**
     * Enables switching between different render APIs.
     */
    class GraphicsContext
    {
    public:
      static RenderAPI getRenderAPI() { return s_renderAPI; }
      static void setRenderAPI(RenderAPI api);

      virtual void onImGUI() {}

      static GraphicsContext *create();

    protected:
      static GraphicsContext *(*createFunction)();

      static RenderAPI s_renderAPI;
    };
  } // namespace Graphics
} // namespace Ore
