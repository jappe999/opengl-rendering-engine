#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "ore/engine/renderer/world_node.hpp"

using namespace glm;

class Camera : public WorldNode
{
public:
  Camera(Node *parent = nullptr);
  ~Camera();

  /**
   * @brief Get the current orientation of the camera.
   */
  vec3 getOrientation();

  /**
   * @brief Set the current orientation of the camera.
   */
  void setOrientation(vec3 orientation);

  /**
   * @brief Get the yaw rotation (X value).
   */
  double getYaw();

  /**
   * @brief Get the pitch rotation (Y value).
   */
  double getPitch();

  /**
   * @brief Rotate relatively.
   */
  void rotate(float angle, vec3 axes);

  /**
   * @brief Set absolute rotation.
   */
  void rotateTo(float angle, vec3 axes);

  const mat4 getViewMatrix();
  const mat4 getProjectionMatrix();

  const vec3 getTargetFront() { return targetFront; }
  const vec3 getTargetRight() { return targetRight; }
  const vec3 getTargetUp() { return targetUp; }

  void setAspectRatio(float ratio);
  float getAspectRatio();

private:
  // The aspect ratio of the camera.
  float aspect;

  // The angle resolved into a direction vector.
  vec3 orientation;

  // The normalized direction vectors.
  vec3 targetFront, targetRight, targetUp;

  double pitch, yaw = 0;

  void updateVectors();
};