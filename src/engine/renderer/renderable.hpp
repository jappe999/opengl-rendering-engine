#pragma once

#include <memory>
#include <glm/gtc/matrix_transform.hpp>
#include <libs/glad/glad.h>
#include <engine/renderer/shader.hpp>
#include <engine/renderer/node.hpp>
#include <engine/renderer/camera.hpp>

using namespace glm;

class Renderable : public Node
{
public:
  Renderable(Node *parent = nullptr) : Node(parent) {}
  ~Renderable() = default;

  virtual void useShader(Shader *shader);

  virtual void bind();
  virtual void render(Camera *camera);

  /**
   * @brief Get the current position of the node.
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
   * @brief Rotate relatively.
   *
   * @param rotation
   */
  void rotate(float degrees, vec3 axes);

  /**
   * @brief Set absolute rotation.
   *
   * @param rotation
   */
  void rotateTo(vec3 rotation);

  /**
   * @brief Scale on individual axes.
   *
   * @param scale
   */
  void scale(vec3 scale);

  /**
   * @brief Scale on all axes.
   *
   * @param scale
   */
  void scale(float scale);

protected:
  GLuint vao;

  Shader *shader;

  mat4 model = mat4(1.0f);

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

  GLuint uniform_model,
      uniform_view,
      uniform_proj;
};