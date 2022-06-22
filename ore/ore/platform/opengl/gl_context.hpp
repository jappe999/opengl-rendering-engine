#include "ore/engine/graphics/hardware_interfaces/graphics_context.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLContext : public GraphicsContext
    {
    public:
      ~OpenGLContext();

      static void makeDefault();

      void onImGUI() override;

    protected:
      static GraphicsContext *createFunctionGL();
    };
  }
}
