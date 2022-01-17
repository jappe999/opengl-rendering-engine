#include "imgui_internal.h"
#include <ore/engine.hpp>
#include "scenes/scene_manager.hpp"

namespace Rock
{
  class GuiDock : public Ore::Node
  {
  public:
    std::string name = "Rock Editor Gui";

    void onStart() override
    {
      SceneManager *sceneManager = new SceneManager();
      addChild(sceneManager);

      Ore::Node::onStart();
    }

    void onUpdate() override
    {
      startDock();
      Ore::Node::onUpdate();
    }

  private:
    void startDock()
    {
      static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_PassthruCentralNode;

      // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
      // because it would be confusing to have two docking targets within each others.
      ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;

      ImGuiViewport *viewport = ImGui::GetMainViewport();
      ImGui::SetNextWindowPos(viewport->Pos);
      ImGui::SetNextWindowSize(viewport->Size);
      ImGui::SetNextWindowViewport(viewport->ID);
      ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
      window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
      window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

      // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
      if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

      // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
      // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
      // all active windows docked into it will lose their parent and become undocked.
      // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
      // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
      ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
      ImGui::Begin(name.c_str(), nullptr, window_flags);
      ImGui::PopStyleVar();
      ImGui::PopStyleVar(2);

      // DockSpace
      ImGuiIO &io = ImGui::GetIO();

      if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
      {
        ImGuiID dockspace_id = ImGui::GetID(name.c_str());
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        static auto first_time = true;
        if (first_time)
        {
          first_time = false;

          ImGui::DockBuilderRemoveNode(dockspace_id); // clear any previous layout
          ImGui::DockBuilderAddNode(dockspace_id, dockspace_flags | ImGuiDockNodeFlags_DockSpace);
          ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->Size);

          // split the dockspace into 2 nodes -- DockBuilderSplitNode takes in the following args in the following order
          //   window ID to split, direction, fraction (between 0 and 1), the final two setting let's us choose which id we want (which ever one we DON'T set as NULL, will be returned by the function)
          //                                                              out_id_at_dir is the id of the node in the direction we specified earlier, out_id_at_opposite_dir is in the opposite direction
          auto dock_id_up = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Up, 0.1f, nullptr, &dockspace_id);
          auto dock_id_right = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Right, 0.2f, nullptr, &dockspace_id);
          auto dock_id_down = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Down, 0.25f, nullptr, &dockspace_id);
          auto dock_id_left = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.2f, nullptr, &dockspace_id);

          // we now dock our windows into the docking node we made above
          ImGui::DockBuilderDockWindow("Scene", dock_id_up);
          ImGui::DockBuilderDockWindow("Node Editor", dock_id_right);
          ImGui::DockBuilderDockWindow("Files", dock_id_down);
          ImGui::DockBuilderDockWindow("Scene Manager", dock_id_left);
          ImGui::DockBuilderFinish(dockspace_id);
        }
      }

      ImGui::End();
    }
  };
} // namespace Rock
