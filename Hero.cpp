#include "Hero.h"

#define ACCEL_X 4
#define ACCEL_Y 4
#define MAX_VX 20
#define MAX_VY 20

Hero::Hero(double X, double Y, double VX, double VY, double AX, double AY):Unit(X,Y,VX,VY,AX,AY)
{
}

void Hero::draw()
{
}

void Hero::collide(Unit* u)
{
}

void Hero::increment()
{
  x+=vx;
  y+=vy;
  //  if(moving)
  if(vx+ax>=MAX_VX)
    vx = MAX_VX;
  else if(vx+ax<=-MAX_VX)
    vx = -MAX_VX;
  else
    vx += ax
  if(vy+ay>=MAX_VY)
    vy = MAX_VY;
  else if(vy+ay<=-MAX_VY)
    vy = -MAX_VY;
  else
    vy += ay;

  //else 
  //  make things go toward 0;
}
