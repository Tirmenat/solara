#include "Hero.h"

Hero::Hero(double X, double Y, double VX, double VY, double AX, double AY):Unit(X,Y,VX,VY,AX,AY)
{
}

void Hero::draw()
{
}

void Hero::collide(Unit* u)
{
}

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
}
