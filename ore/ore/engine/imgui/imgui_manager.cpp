#include "ore/engine/core/application.hpp"
#include "imgui_manager.hpp"

namespace Ore
{
  ImGuiManager::ImGuiManager()
  {
  }

  ImGuiManager::~ImGuiManager()
  {
    ImGui::DestroyContext();
  }

  void ImGuiManager::onStart()
  {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    Window window = Application::getInstance().getWindow();
    m_imGuiRenderer = Graphics::ImGuiRenderer::create(window.getWidth(), window.getHeight(), true);

    if (m_imGuiRenderer)
      m_imGuiRenderer->onStart();
  }

  void ImGuiManager::onEvent(Events::Event &event)
  {
    m_imGuiRenderer->onEvent(event);
  }

  void ImGuiManager::onUpdate()
  {
    m_imGuiRenderer->newFrame();
  }

  void ImGuiManager::render(Camera *camera)
  {
    m_imGuiRenderer->render(camera);
  }
} // namespace Ore
