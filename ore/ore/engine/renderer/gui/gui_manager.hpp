#pragma once

#include "ore/engine/renderer/node.hpp"

namespace Ore
{
  class GuiManager : public Node
  {
  public:
    GuiManager();
    ~GuiManager() = default;

    void onUpdate() override;
    void render();

  private:
    void setStyle();
  };
} // namespace Ore
