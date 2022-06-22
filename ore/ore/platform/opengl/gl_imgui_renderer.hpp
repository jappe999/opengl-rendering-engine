#include "ore/engine/graphics/hardware_interfaces/imgui_renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLImGuiRenderer : public ImGuiRenderer
    {
    public:
      ~OpenGLImGuiRenderer();

      void makeDefault();

      void render() override;

    protected:
      OpenGLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen);

      static ImGuiRenderer *createFuncGL(uint32_t, uint32_t, bool);
    };
  } // namespace Graphics
} // namespace Ore
