#include <stdint.h>

namespace Ore
{
  namespace Graphics
  {
    class ImGuiRenderer
    {
    public:
      virtual void render();

    protected:
      static ImGuiRenderer *(*createFunc)(uint32_t, uint32_t, bool);
    };
  } // namespace Graphics
} // namespace Ore
