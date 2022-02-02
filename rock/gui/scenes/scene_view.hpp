#include <GLFW/glfw3.h>
#include <ore/engine.hpp>

namespace Rock
{
  class SceneView : public Ore::GuiWindow
  {
    void onGui() override
    {
      if (begin("Scene View"))
      {
      }
      end();
    }
  };
} // namespace Rock
