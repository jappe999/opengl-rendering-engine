#include "renderer.hpp"

namespace Ore
{
  namespace Graphics
  {
    Renderer *(*Renderer::createFunction)() = nullptr;

    Renderer *Renderer::s_instance;

    void Renderer::init()
    {
      s_instance = createFunction();
      s_instance->internalInit();
    }

    void Renderer::release()
    {
      delete s_instance;
      s_instance = nullptr;
    }
  } // namespace Graphics
} // namespace Ore
