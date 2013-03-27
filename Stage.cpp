#include "Stage.h"

Stage::Stage()
{
}

int isInBounds(){
  if(a>size_x || a<0 || b<size_y || b<0) return 0;
  else return 1;

}
