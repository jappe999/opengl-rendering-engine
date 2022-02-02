#pragma once

#include "imgui.h"
#include "ore/engine/renderer/node.hpp"

namespace Ore
{
  class GuiWindow : public Node
  {
  public:
    void show();

  protected:
    virtual bool begin(std::string name);
    void end();
    bool open;
  };
} // namespace Ore
