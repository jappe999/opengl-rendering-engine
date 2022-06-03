#include "ore/engine/graphics/hardware_interfaces/graphics_context.hpp"

namespace Ore
{
    namespace Graphics
    {
        GLContext() = default;
        ~GLContext() = default;

        void GLContext::makeDefault()
        {
            createFunction = createFunctionGL;
        }

        static GraphicsContext *createFunctionGL()
        {
            return new GLContext();
        }
    }
}
