#include "ore/platform/opengl/gl_context.hpp"

namespace Ore
{
    namespace Graphics
    {
        void GLContext::makeDefault()
        {
            createFunction = createFunctionGL;
        }

        GraphicsContext *GLContext::createFunctionGL()
        {
            return new GLContext();
        }
    }
}
