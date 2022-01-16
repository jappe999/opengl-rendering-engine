#include "rock.hpp"

int main()
{
  Rock::RockEditor app;

  if (app.create(480, 360))
    app.start();
}