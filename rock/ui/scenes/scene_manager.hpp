#include <string>
#include <ore/engine.hpp>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Rock
{
  class SceneManager : public Ore::Node
  {

  public:
    void onUpdate() override;

  protected:
    Ore::Scene *scene;

  private:
    void openScene(std::string path);
    void closeCurrentScene();
  };
} // namespace Rock
