#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/behavior.hpp>
#include <engine/core/application.hpp>

using namespace glm;

class CubeController : public Behavior
{
public:
  CubeController(WorldNode *node) : Behavior(node) {}

  void onUpdate()
  {
    node->translate(vec3(0.1, 0.0, 0.0) * Application::getInstance().getDeltaTime());
  }
};

ORE_REGISTER_NODE(CubeController, "cube_controller");