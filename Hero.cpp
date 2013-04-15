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

<<<<<<< HEAD
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
=======
void Hero::processEvent(SDL_Event event)
{
  switch(event.type)
  {
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
      { 
        case SDLK_UP: 
          ay=-ACCEL_Y;
          break;
        case SDLK_DOWN:
          ay=ACCEL_Y;
          break;
        case SDLK_LEFT:
          ax=-ACCEL_Y;
          //Set sprite to left sprite
          break;
        case SDLK_RIGHT:
          ax=ACCEL_X;
          //Set sprite to right sprite
          break;
      }
      break;
    case SDL_KEYUP:
      switch(event.key.keysym.sym)
      {
        case SDLK_UP:
          ay=0;
          break;
        case SDLK_DOWN:
          ay=0;
          break;
        case SDLK_LEFT:
          ax=0;
          break;
        case SDLK_RIGHT:
          ax=0;
          break;
      }
  }
>>>>>>> 58beb1f9ad4d5a87b9ffcf8222cda1611729d07e
}
