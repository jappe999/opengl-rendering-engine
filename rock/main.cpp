#include "rock.hpp"

int main()
{
  Ore::RockEditor app;

  if (app.create(480, 360))
    app.start();
}