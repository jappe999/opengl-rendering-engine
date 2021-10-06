#include <engine/renderer/behavior.hpp>

class CameraController : public Behavior
{
public:
  CameraController(Node *node) : Behavior(node) {}

  bool onWindowResize(WindowResizeEvent &event) override
  {
    std::cout << event.toString() << std::endl;
    return true;
  }

  bool onMouseMove(MouseMoveEvent &event) override
  {
    std::cout << event.toString() << std::endl;
    return true;
  }
};