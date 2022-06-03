#include "ore/engine/graphics/hardware_interfaces/graphics_context.hpp"

namespace Ore
{
  namespace Graphics
  {
    class GLContext : public GraphicsContext
    {
    public:
      static void makeDefault();

    protected:
      static GraphicsContext *createFunctionGL();
    };
  }
}
