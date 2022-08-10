#include <stdint.h>
#include "ore/engine/renderer/node.hpp"

namespace Ore
{
  namespace Graphics
  {
    class ImGuiRenderer : public Node
    {
    public:
      ImGuiRenderer() {}

      static ImGuiRenderer *create(uint32_t width, uint32_t height, bool clearScreen);

      virtual void newFrame();

    protected:
      static ImGuiRenderer *(*createFunc)(uint32_t, uint32_t, bool);
    };
  } // namespace Graphics
} // namespace Ore
