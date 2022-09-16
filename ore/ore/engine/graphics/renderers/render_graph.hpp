#pragma once

#include <stdint.h>
#include "../hardware_interfaces/renderer.hpp"

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

      void onImGUI()
      {
        // Show stats
      }
    };
  } // namespace Graphic

} // namespace Ore
