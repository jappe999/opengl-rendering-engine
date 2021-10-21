#include <memory>
#include <iostream>
#include <engine/core/application.hpp>
#include "cube.hpp"
#include "camera_controller.hpp"

class MyApp : public Application
{
public:
  void onStart() override
  {
    loadScene("assets/scenes/empty-void-with-cube.yml");

    // scene = new Scene();

    // camera = NodeFactory::create("ore_camera")->cast<Camera *>();
    // camera->setAspectRatio(float(width) / height);
    // CameraController *cameraController = NodeFactory::create("camera_controller", camera)->cast<CameraController *>();
    // camera->addBehavior(cameraController);
    // scene->addNode(camera);

    // Cube *cube = NodeFactory::create("cube")->cast<Cube *>();
    // cube->useShader(Shader::acquire("base"));
    // cube->bind();
    // cube->rotate(45.0f, vec3(0, 1, 0));
    // scene->addNode(cube);
  }

  void onDestroy() override
  {
    cout << "See you soon!" << endl;
  }
};

int main()
{
  MyApp app;

  if (app.create(480, 360))
    app.start();

  return 0;
}