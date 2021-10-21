#pragma once

#include <string>
#include <engine/renderer/scene.hpp>
#include <engine/renderer/behavior.hpp>

class SceneLoader
{
public:
  static Scene *deserialize(std::string path);
  static std::string serialize(const std::string path);
};