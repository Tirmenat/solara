#include "Hero.h"

#define ACCEL_X 4
#define ACCEL_Y 4
#define MAX_VX 20
#define MAX_VY 20

Hero::Hero(double X, double Y, double VX, double VY, double AX, double AY, int location):Unit(X,Y,VX,VY,AX,AY,location)
{
}

void Hero::collide(Unit* u)
{
}

void Hero::increment()
{
  /*  x+=vx;
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
  vy += ay;*/
}
  //else 
  //  make things go toward 0;
void Hero::processEvent()
{
  /*  Uint8 *keystates = SDL_GETKEYSTATE( NULL );
  if( keystates[SDLK_UP] && keystates [SDLK_DOWN] )
  {
    ay=0;
    //motiony=1;
  }
  else if( keystates[SDLK_UP] )
  {
    ay=-ACCEL_Y;
    //motiiony=1;
  }
  else if ( keystates[SDLK_DOWN] )
  {
    ay=ACCEL_Y;
    //motiony=1;
  }
  else
  {
    //motiony=0;
  }
  if( keystates[SDLK_LEFT] && keystates[SDLK_RIGHT] )
  {
    ax=0;
    //motionx=1;
  }
  else if (keystates[SDLK_LEFT])
  {
    ax=-ACCEL_X;
    //motionx=1;
  }
  else if (keystates[SDLK_RIGHT])
  {
    ax=ACCEL_X;
    //motionx=1;
  }
  else
  {
    //motionx=0;
  }
  //Old Event based code
  /*switch(event.type)
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
      }*/
}
