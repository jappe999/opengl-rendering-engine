#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/node.hpp>

using namespace glm;

class Camera : public Node
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
   * @brief Get the current position of the camera.
   *
   * @return vec3
   */
  vec3 getPosition();

  /**
   * @brief Translate the node relative to the current position.
   *
   * @param translation
   */
  void translate(vec3 translation);

  /**
   * @brief Translate the node to the given position.
   *
   * @param position
   */
  void translateTo(vec3 position);

  /**
   * @brief Get the yaw rotation (X value).
   *
   * @return double
   */
  double getYaw();

  /**
   * @brief Get the pitch rotation (Y value).
   *
   * @return double
   */
  double getPitch();

  /**
   * @brief Rotate relatively.
   *
   * @param rotation
   */
  void rotate(vec3 rotation);

  /**
   * @brief Set absolute rotation.
   *
   * @param rotation
   */
  void rotateTo(vec3 rotation);

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

  // The inverted position of the camera.
  vec3 position;

  // The normalized direction vectors.
  vec3 targetFront, targetRight, targetUp;

  double pitch, yaw = 0;

  void updateVectors();
};