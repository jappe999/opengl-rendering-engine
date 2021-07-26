#include <iostream>
#include <engine/application.hpp>

using namespace std;

class MyApp : public Application
{
public:
  void onStart() override
  {
    cout << "Hello World!" << endl;
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