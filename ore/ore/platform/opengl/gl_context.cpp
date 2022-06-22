#include "gl.hpp"
#include "imgui.h"
#include "ore/platform/opengl/gl_context.hpp"

namespace Ore
{
    namespace Graphics
    {
        void OpenGLContext::onImGUI()
        {
            ImGui::TextUnformatted("%s", (const char *)(glGetString(GL_RENDERER)));
            ImGui::TextUnformatted("%s", (const char *)(glGetString(GL_VERSION)));
            ImGui::TextUnformatted("%s", (const char *)(glGetString(GL_SHADING_LANGUAGE_VERSION)));
            ImGui::TextUnformatted("%s", (const char *)(glGetString(GL_VENDOR)));
        }

        void OpenGLContext::makeDefault()
        {
            createFunction = createFunctionGL;
        }

        GraphicsContext *OpenGLContext::createFunctionGL()
        {
            return new OpenGLContext();
        }
    }
}
