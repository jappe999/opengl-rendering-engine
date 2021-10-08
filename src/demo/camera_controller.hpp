#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/behavior.hpp>

using namespace glm;

class CameraController : public Behavior
{
public:
  CameraController(Node *node) : Behavior(node)
  {
    camera = dynamic_cast<Camera *>(node);
  }

  bool onWindowResize(WindowResizeEvent &event) override
  {
    camera->setAspectRatio((float)event.getWidth() / event.getHeight());
    return true;
  }

  bool onMouseMove(MouseMoveEvent &event) override
  {
    static float maxY = 22.0f;

    double relativeX = (prevX - event.getX()) * 0.5;
    double relativeY = (prevY - event.getY()) * 0.5;
    prevX = event.getX();
    prevY = event.getY();

    float nextPitch = relativeY + camera->getPitch();

    if (nextPitch > maxY)
      relativeY -= nextPitch - maxY;
    if (nextPitch < -maxY)
      relativeY -= nextPitch + maxY;

    camera->rotate(vec3(-relativeX, relativeY, 0.0));
    return true;
  }

private:
  Camera *camera;

  double prevX = 0, prevY = 0;
};