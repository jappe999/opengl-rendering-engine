#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "ore/engine/renderer/node.hpp"

using namespace glm;

namespace Ore
{
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
    virtual void rotate(float angle, vec3 axes);

    /**
   * @brief Set absolute rotation.
   *
   * @param angle The angle to rotate
   * @param axes The axes to rotate on
   */
    virtual void rotateTo(float angle, vec3 axes);

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
    vec3 position = vec3(1.0f);

    /**
   * @brief Object rotation.
   *
   */
    vec4 rotation = vec4(1.0f);

    /**
   * @brief Object scale.
   *
   */
    vec3 scaling = vec3(1.0f);
  };
} // namespace Ore
