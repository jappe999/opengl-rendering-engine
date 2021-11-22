#include <glm/gtc/matrix_transform.hpp>
#include <ore/engine.hpp>

using namespace glm;

class CameraController : public Ore::Behavior
{
public:
  CameraController(Ore::WorldNode *node) : Behavior(node)
  {
    camera = node->cast<Ore::Camera *>();
    prevYaw = Ore::Input::getCursorPosition().x;
    prevPitch = Ore::Input::getCursorPosition().y;
  }

  void onUpdate()
  {
    move();
    rotate();
  }

  bool onWindowResize(Ore::Events::WindowResizeEvent &event) override
  {
    camera->setAspectRatio((float)event.getWidth() / event.getHeight());
    return true;
  }

private:
  Ore::Camera *camera;

  float movementSpeed = 2.0f;

  bool rotateZLeft = true;

  float prevYaw = 0, prevPitch = 0;

  void move()
  {
    float speed = movementSpeed * Ore::Application::getInstance().getDeltaTime();

    float forward = 0;
    if (Ore::Input::isKeyPressed(GLFW_KEY_W) || Ore::Input::isKeyPressed(GLFW_KEY_UP))
      forward = speed;
    else if (Ore::Input::isKeyPressed(GLFW_KEY_S) || Ore::Input::isKeyPressed(GLFW_KEY_DOWN))
      forward = -speed;

    camera->translate(camera->getTargetFront() * forward);

    float right = 0;
    if (Ore::Input::isKeyPressed(GLFW_KEY_A) || Ore::Input::isKeyPressed(GLFW_KEY_LEFT))
      right = -speed;
    else if (Ore::Input::isKeyPressed(GLFW_KEY_D) || Ore::Input::isKeyPressed(GLFW_KEY_RIGHT))
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
    vec2 position = Ore::Input::getCursorPosition();

    float relativeYaw = (prevYaw - position.x) * movementSpeed * Ore::Application::getInstance().getDeltaTime();
    float relativePitch = (prevPitch - position.y) * movementSpeed * Ore::Application::getInstance().getDeltaTime();
    prevYaw = position.x;
    prevPitch = position.y;

    float nextPitch = relativePitch + camera->getPitch();

    // Clamp between the maxY values.
    if (nextPitch > maxY)
      relativePitch -= nextPitch - maxY;
    if (nextPitch < -maxY)
      relativePitch -= nextPitch + maxY;

    camera->rotate(-relativeYaw, vec3(1.0f, 0.0f, 0.0f));
    camera->rotate(relativePitch, vec3(0.0f, 1.0f, 0.0f));
  }
};

ORE_REGISTER_NODE(CameraController, "camera_controller");