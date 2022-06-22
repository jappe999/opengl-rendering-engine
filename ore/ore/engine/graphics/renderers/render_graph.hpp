#pragma once

#include <stdint.h>

namespace Ore
{
  namespace Graphics
  {
    /**
     * Render scene objects using renderer passes.
     */
    class RenderGraph
    {
    public:
      RenderGraph(int32_t width, int32_t height);
      ~RenderGraph();

      void onImGUI() {}
    };
  } // namespace Graphic

} // namespace Ore
