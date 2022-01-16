#include <string>
#include <ore/engine.hpp>

namespace Rock
{
  class SceneManager : public Ore::Node
  {
  public:
    void onUpdate() override;

  private:
    std::string currentScene = "empty";
  };
} // namespace Rock
