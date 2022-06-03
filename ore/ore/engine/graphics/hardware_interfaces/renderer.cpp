#include "renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    void Renderer::init()
    {
      s_instance = createFunction();
    }

    void Renderer::release()
    {
      delete s_instance;
      s_instance = nullptr;
    }
  } // namespace Graphics
} // namespace Ore
