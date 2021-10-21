#include <yaml-cpp/yaml.h>
#include <engine/core/scene_loader.hpp>
#include <engine/renderer/renderable.hpp>
#include <engine/utils/filesystem.hpp>

Scene *SceneLoader::deserialize(std::string path)
{
  Scene *scene = new Scene();

  YAML::Node config = YAML::LoadFile(getPath(path));

  std::cout << "Loading scene '" << config["name"] << "'" << std::endl;

  for (auto nodeConfig : config["nodes"])
  {
    Node *node = NodeFactory::create(nodeConfig["type"].as<std::string>());

    if (node->isDerivedFrom<Camera>() && nodeConfig["properties"]["main"])
    {
      scene->setMainCamera(node->cast<Camera *>());
    }

    if (nodeConfig["position"])
    {
      // TODO: set initial position.
    }

    if (nodeConfig["rotation"])
    {
      // TODO: set initial rotation.
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
    }

    scene->addNode(node);
  }

  return scene;
}

std::string SceneLoader::serialize(const std::string path)
{
  return "";
}
