//main program
#include <iostream>
#include "Stage.h"
#include "Hero.h"

using namespace std;

int main(void)
{
  Stage stages;
  stages.addArea(0,0,500,500);
  Hero units(200,200);
  stages.addUnit(&units);

  cout << units.getx() << units.gety() << units.getvx() << units.getvy();
}
