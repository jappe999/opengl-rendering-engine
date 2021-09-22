#include "camera.hpp"

Camera::Camera()
{
  targetFront = vec3(0.0f, 0.0f, 1.0f);
  position = vec3(0.0f, 0.0f, -5.0f);
  orientation = vec3(0.0f, 0.0f, 0.0f);
  yaw = 0;
  pitch = 0;

  updateVectors();
}

Camera::~Camera()
{
}

vec3 Camera::getPosition()
{
  return position;
}

void Camera::setPosition(vec3 position)
{
  this->position = position;
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