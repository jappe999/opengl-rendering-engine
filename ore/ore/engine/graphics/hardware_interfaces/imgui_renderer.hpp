#include <stdint.h>

namespace Ore
{
  namespace Graphics
  {
    class ImGuiRenderer
    {
    public:
      ImGuiRenderer() {}
      virtual void render() = 0;

    protected:
      static ImGuiRenderer *(*createFunc)(uint32_t, uint32_t, bool);
    };
  } // namespace Graphics
} // namespace Ore
