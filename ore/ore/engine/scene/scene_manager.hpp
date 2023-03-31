#pragma once

#include <string>
#include <vector>
#include "ore/engine/renderer/scene.hpp"

namespace Ore
{
  class SceneManager : public Node
  {
  public:
    static SceneManager &get()
    {
      if (!s_instance)
        s_instance = new SceneManager();

      return *s_instance;
    }

    Scene *preloadScene(std::string path);
    void loadScene(Scene *scene);
    void loadScene(std::string path);
    void switchScene();
    void unloadCurrentScene();

    void onUpdate() override;

  private:
    SceneManager();
    ~SceneManager();

    static SceneManager *s_instance;

    Scene *m_preloadedScene;
    Scene *m_activeScene;
  };
} // namespace Orr
