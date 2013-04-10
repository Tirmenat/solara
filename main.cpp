//main program
#include <iostream>
#include "Stage.h"
#include "Hero.h"

using namespace std;

int main(void)
{
  Stage stages(100,100);
  stages.addArea(0,0,500,500);
  Hero units(1.0,1.0,1.0,1.0,1.0,1.0);
  stages.addUnit(&units);

  cout << units.getx() << endl << units.gety() << endl << units.getvx() << endl << units.getvy() << endl; //testcode
}
