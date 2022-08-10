#pragma once

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
      Renderer() = default;
      virtual ~Renderer() = default;

      static void init();
      static void release();

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
