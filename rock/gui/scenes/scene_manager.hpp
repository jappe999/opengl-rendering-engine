#include <ore/engine.hpp>
namespace Rock
{
  class SceneManager : public Ore::GuiWindow
  {
  public:
    void onGui() override;

  private:
    std::string currentScene = "empty";
  };
} // namespace Rock
