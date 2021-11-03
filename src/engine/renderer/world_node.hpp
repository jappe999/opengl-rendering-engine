#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include <engine/renderer/node.hpp>

using namespace glm;

class WorldNode : public Node
{
public:
  WorldNode(Node *parent = nullptr) : Node(parent) {}

  /**
   * @brief Get the current position of the node.
   */
  virtual vec3 getPosition();

  /**
   * @brief Translate the node relative to the current position.
   */
  virtual void translate(vec3 translation);

  /**
   * @brief Translate the node to the given position.
   */
  virtual void translateTo(vec3 position);

  /**
   * @brief Rotate relatively.
   *
   * @param angle The angle to rotate
   * @param axes The axes to rotate on
   */
  virtual void rotate(vec3 rotation);

  /**
   * @brief Set absolute rotation.
   *
   * @param angle The angle to rotate
   * @param axes The axes to rotate on
   */
  virtual void rotateTo(vec3 rotation);

  /**
   * @brief Scale on individual axes.
   */
  virtual void scale(vec3 scale);

  /**
   * @brief Scale on all axes.
   */
  virtual void scale(float scale);

protected:
  /**
   * @brief Object position.
   *
   */
  vec3 position;

  /**
   * @brief Object rotation.
   *
   */
  vec4 rotation;

  /**
   * @brief Object scale.
   *
   */
  vec3 scaling;
};