//main program
#include <iostream>
#include "Unit.h"
#include "Stage.h"
#include "Hero.h"

using namespace std;

int main(void)
{
  Stage stage;
  stage.addArea(0,0,500,500);
  Hero unit(200,200);
  stage.addUnit(&unit);
}
