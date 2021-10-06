#include <memory>
#include <iostream>
#include <engine/core/application.hpp>
#include <engine/renderer/node.hpp>
#include "cube.hpp"
#include "camera_controller.hpp"

class MyApp : public Application
{
public:
  void onStart() override
  {
    scene = new Scene();

    camera = new Camera();
    camera->setAspectRatio(float(width) / height);
    CameraController *cameraController = new CameraController(camera);
    camera->addBehavior(cameraController);
    scene->addNode(camera);

    Renderable *cube = new Cube();
    cube->useShader(Shader::acquire("base"));
    cube->bind();
    scene->addNode(cube);
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