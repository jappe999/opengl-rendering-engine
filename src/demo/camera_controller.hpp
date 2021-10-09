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

    double relativeYaw = (prevYaw - event.getX()) * 0.5;
    double relativePitch = (prevPitch - event.getY()) * 0.5;
    prevYaw = event.getX();
    prevPitch = event.getY();

    float nextPitch = relativePitch + camera->getPitch();

    // Clamp between the maxY values.
    if (nextPitch > maxY)
      relativePitch -= nextPitch - maxY;
    if (nextPitch < -maxY)
      relativePitch -= nextPitch + maxY;

    camera->rotate(vec3(-relativeYaw, relativePitch, 0.0));
    return true;
  }

  bool onKeyPress(KeyPressEvent &event) override
  {
    move(event.getKey());
    return true;
  }

  bool onKeyRepeat(KeyRepeatEvent &event) override
  {
    move(event.getKey());
    return true;
  }

private:
  Camera *camera;

  float movementSpeed = 0.5f;

  double prevYaw = 0, prevPitch = 0;

  void move(uint32_t key)
  {
    float speed = 0.1;

    float forward = 0;
    if (key == GLFW_KEY_W || key == GLFW_KEY_UP)
      forward = speed;
    else if (key == GLFW_KEY_S || key == GLFW_KEY_DOWN)
      forward = -speed;

    camera->translate(camera->getTargetFront() * forward);

    float right = 0;
    if (key == GLFW_KEY_A || key == GLFW_KEY_LEFT)
      right = -speed;
    else if (key == GLFW_KEY_D || key == GLFW_KEY_RIGHT)
      right = speed;
    camera->translate(camera->getTargetRight() * right);
  }
};