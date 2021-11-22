#include <yaml-cpp/yaml.h>
#include "ore/engine/core/scene_loader.hpp"
#include "ore/engine/renderer/renderable.hpp"
#include "ore/engine/utils/filesystem.hpp"

Scene *SceneLoader::deserialize(std::string path)
{
  Scene *scene = new Scene();

  YAML::Node config = YAML::LoadFile(getPath(path));

  std::cout << "Loading scene '" << config["name"] << "'" << std::endl;

  for (auto nodeConfig : config["nodes"])
  {
    WorldNode *node = NodeFactory::create(nodeConfig["type"].as<std::string>())->cast<WorldNode *>();

    if (node->isDerivedFrom<Camera>() && nodeConfig["properties"]["main"])
    {
      scene->setMainCamera(node->cast<Camera *>());
    }

    if (nodeConfig["position"])
    {
      std::vector<float> position = nodeConfig["position"].as<std::vector<float>>();
      node->cast<WorldNode *>()->translateTo(vec3(position[0], position[1], position[2]));
    }

    if (nodeConfig["rotation"])
    {
      std::vector<float> rotation = nodeConfig["rotation"].as<std::vector<float>>();
      node->cast<WorldNode *>()->rotateTo(rotation[3], vec3(rotation[0], rotation[1], rotation[2]));
    }

    if (node->isDerivedFrom<Renderable>())
    {
      Renderable *renderable = node->cast<Renderable *>();
      for (auto shaderName : nodeConfig["shaders"])
      {
        renderable->useShader(Shader::acquire(shaderName.as<std::string>()));
        renderable->bind();
      }
    }

    for (auto script : nodeConfig["scripts"])
    {
      Behavior *behavior = NodeFactory::create(script.as<std::string>(), node)
                               ->cast<Behavior *>();
      node->addBehavior(behavior);

      std::cout << "Added script '" << script.as<std::string>() << "' to '"
                << nodeConfig["type"].as<std::string>() << "'" << std::endl;
    }

    scene->addNode(node);
  }

  return scene;
}

std::string SceneLoader::serialize(const std::string path)
{
  return "";
}
