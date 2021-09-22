#pragma once

#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Camera
{
public:
  Camera();
  ~Camera();

  vec3 getPosition();
  void setPosition(vec3 position);

  const mat4 getViewMatrix();
  const mat4 getProjectionMatrix();

  void setAspectRatio(float ratio);
  float getAspectRatio();

private:
  // The aspect ratio of the camera.
  float aspect;

  // The angle resolved into a direction vector.
  vec3 orientation;

  // The inverted position of the camera.
  vec3 position;

  // The normalized direction vectors.
  vec3 targetFront, targetRight, targetUp;

  float pitch, yaw;

  void updateVectors();
};
