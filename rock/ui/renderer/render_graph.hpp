#include <ore/engine.hpp>

namespace Rock
{
  class RenderGraph : public Ore::Node
  {
  public:
    void onImGUI() override;
  };
} // namespace Rock
