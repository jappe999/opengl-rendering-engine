#include "ore/engine/graphics/hardware_interfaces/imgui_renderer.hpp"
#include "ore/engine/events/window.hpp"

namespace Ore
{
  namespace Graphics
  {
    class OpenGLImGuiRenderer : public ImGuiRenderer
    {
    public:
      OpenGLImGuiRenderer(uint32_t width, uint32_t height, bool clearScreen);
      ~OpenGLImGuiRenderer();

      static void makeDefault();

      void newFrame() override;
      void render(Camera *camera) override;
      void onEvent(Events::Event &event) override;

    protected:
      static ImGuiRenderer *createFuncGL(uint32_t, uint32_t, bool);

    private:
      bool onWindowResize(Events::WindowResizeEvent &event);

      bool m_clearScreen;
    };
  } // namespace Graphics
} // namespace Ore
