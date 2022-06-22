#pragma once

namespace Ore
{
  namespace Graphics
  {
    /**
     * Base class for rendering objects.
     */
    class IRenderer
    {
    public:
      virtual ~IRenderer() = default;

      virtual void init() = 0;
      virtual void beginScene() = 0;
      virtual void renderScene() = 0;
    };
  } // namespace Graphics
} // namespace Ore
