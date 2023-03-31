#include "scene_manager.hpp"
#include "ore/engine/core/application.hpp"
#include "ore/engine/core/scene_loader.hpp"

namespace Ore
{
  SceneManager::SceneManager()
  {
    s_instance = this;
  }

  SceneManager::~SceneManager() {}

  Scene *SceneManager::preloadScene(std::string path)
  {
    m_preloadedScene = SceneLoader::deserialize(path);
    return m_preloadedScene;
  }

  void SceneManager::loadScene(Scene *scene)
  {
    m_preloadedScene = scene;
    switchScene();
  }

  void SceneManager::loadScene(std::string path)
  {
    preloadScene(path);
    switchScene();
  }

  void SceneManager::switchScene()
  {
    if (m_preloadedScene == nullptr)
    {
      throw "No scene loaded. Please preload the scene before switching.";
    }

    unloadCurrentScene();
    m_activeScene = m_preloadedScene;

    Application::getInstance().addNode(m_activeScene);
  }

  void SceneManager::unloadCurrentScene()
  {
    if (m_activeScene != nullptr)
    {
      Application::getInstance().removeNode(m_activeScene);

      delete m_activeScene;
      m_activeScene = nullptr;
    }
  }

  void SceneManager::onUpdate()
  {
  }
} // namespace Ore
