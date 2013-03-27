#include "Stage.h"
//DOES THIS WORK???

Stage::Stage()
{
}

int isInBounds(){
  if(a>size_x || a<0 || b<size_y || b<0) return 0;
  else return 1;
}

void addUnit(Unit spr, double x, double y){
  spr.setX(x);
  spr.setY(y);
}

void removeUnit(Unit spr){
  
}
