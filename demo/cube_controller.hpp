#include <glm/gtc/matrix_transform.hpp>
#include <ore/engine.hpp>

using namespace glm;

class CubeController : public Ore::Behavior
{
public:
  CubeController(Ore::WorldNode *node) : Ore::Behavior(node) {}

  void onUpdate()
  {
    node->translate(vec3(0.1, 0.0, 0.0) * Ore::Application::getInstance().getDeltaTime());
  }
};

ORE_REGISTER_NODE(CubeController, "cube_controller");