#include "demo.hpp"

int main(int argc, char **argv)
{
  DerivedApplication app;

  if (app.create(480, 360, true))
    app.start();

  return 0;
}