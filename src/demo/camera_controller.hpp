#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/behavior.hpp>
#include <engine/core/input.hpp>

using namespace glm;

class CameraController : public Behavior
{
public:
  CameraController(Node *node) : Behavior(node)
  {
    camera = node->cast<Camera *>();
  }

  void onUpdate()
  {
    move();
    rotate();
  }

  bool onWindowResize(WindowResizeEvent &event) override
  {
    camera->setAspectRatio((float)event.getWidth() / event.getHeight());
    return true;
  }

private:
  Camera *camera;

  float movementSpeed = 2.0f;

  bool rotateZLeft = true;

  double prevYaw = 0, prevPitch = 0;

  void move()
  {
    float speed = movementSpeed * Application::getInstance().getDeltaTime();

    float forward = 0;
    if (Input::isKeyPressed(GLFW_KEY_W) || Input::isKeyPressed(GLFW_KEY_UP))
      forward = speed;
    else if (Input::isKeyPressed(GLFW_KEY_S) || Input::isKeyPressed(GLFW_KEY_DOWN))
      forward = -speed;

    camera->translate(camera->getTargetFront() * forward);

    float right = 0;
    if (Input::isKeyPressed(GLFW_KEY_A) || Input::isKeyPressed(GLFW_KEY_LEFT))
      right = -speed;
    else if (Input::isKeyPressed(GLFW_KEY_D) || Input::isKeyPressed(GLFW_KEY_RIGHT))
      right = speed;

    camera->translate(camera->getTargetRight() * right);

    vec3 orientation = camera->getOrientation();
    if (forward != 0 || right != 0)
    {
      if (orientation.z >= 0.05)
        rotateZLeft = true;
      else if (orientation.z <= -0.05)
        rotateZLeft = false;

      orientation.z += rotateZLeft ? -0.005 : 0.005;
    }
    else
    {
      if (orientation.z > 0.005)
        orientation.z -= 0.005;
      else if (orientation.z < -0.005)
        orientation.z += 0.005;
      else
        orientation.z = 0;
    }
    camera->setOrientation(orientation);
  }

  void rotate()
  {
    static float maxY = 22.0f;
    vec2 position = Input::getCursorPosition();

    double relativeYaw = (prevYaw - position.x) * movementSpeed * Application::getInstance().getDeltaTime();
    double relativePitch = (prevPitch - position.y) * movementSpeed * Application::getInstance().getDeltaTime();
    prevYaw = position.x;
    prevPitch = position.y;

    float nextPitch = relativePitch + camera->getPitch();

    // Clamp between the maxY values.
    if (nextPitch > maxY)
      relativePitch -= nextPitch - maxY;
    if (nextPitch < -maxY)
      relativePitch -= nextPitch + maxY;

    camera->rotate(vec3(-relativeYaw, relativePitch, 0.0));
  }
};

ORE_REGISTER_NODE(CameraController, "camera_controller");