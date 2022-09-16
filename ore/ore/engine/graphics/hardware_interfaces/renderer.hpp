#pragma once

#include "ore/engine/events/window.hpp"

namespace Ore
{
  namespace Graphics
  {
    /**
     * Base class for different Graphics libraries.
     */
    class Renderer
    {
    public:
      Renderer() {}
      virtual ~Renderer() = default;

      static void init();
      static void release();
      virtual void internalInit() = 0;

      virtual void onResize(Events::WindowResizeEvent &event) = 0;

      inline static Renderer *get()
      {
        return s_instance;
      }

    protected:
      static Renderer *(*createFunction)();
      static Renderer *s_instance;
    };
  } // namespace Graphics
} // namespace Ore