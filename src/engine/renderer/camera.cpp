#include <engine/renderer/camera.hpp>

ORE_REGISTER_NODE(Camera, "ore_camera");

Camera::Camera(Node *parent) : WorldNode(parent)
{
  targetFront = vec3(0.0f, 0.0f, -1.0f);
  position = vec3(0.0f, 0.0f, -5.0f);
  orientation = vec3(0.0f, 1.0f, 0.0f);
  yaw = 90;
  pitch = 0;

  updateVectors();
}

Camera::~Camera()
{
}

vec3 Camera::getOrientation()
{
  return orientation;
}

void Camera::setOrientation(vec3 orientation)
{
  this->orientation = orientation;
}

double Camera::getPitch()
{
  return pitch;
}

double Camera::getYaw()
{
  return yaw;
}

void Camera::rotate(float angle, vec3 axes)
{
  std::cout << "Angle: " << angle << ", X: " << axes.x << ", Y: " << axes.y << ", Z: " << axes.z << std::endl
            << "Yaw: " << yaw << ", Pitch: " << pitch << ", Roll: " << orientation.z << std::endl;
  yaw += angle * axes.x;
  pitch += angle * axes.y;
  orientation.z += angle * axes.z;
}

void Camera::rotateTo(float angle, vec3 axes)
{
  yaw = angle * axes.x;
  pitch = angle * axes.y;
  orientation.z = angle * axes.z;
}

void Camera::updateVectors()
{
  vec3 direction;
  direction.x = cos(radians(yaw)) * cos(radians(pitch));
  direction.y = sin(radians(pitch));
  direction.z = sin(radians(yaw)) * cos(radians(pitch));

  targetFront = normalize(direction);
  targetRight = normalize(cross(targetFront, orientation));
  targetUp = normalize(cross(targetRight, targetFront));
};

const mat4 Camera::getViewMatrix()
{
  updateVectors();
  return lookAt(position, position + targetFront, targetUp);
}

const mat4 Camera::getProjectionMatrix()
{
  return perspective(radians(45.0f), aspect, 0.01f, 200.0f);
}

void Camera::setAspectRatio(float ratio)
{
  aspect = ratio;
}

float Camera::getAspectRatio()
{
  return aspect;
}