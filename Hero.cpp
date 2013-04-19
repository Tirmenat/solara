#include "Hero.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO .001
#define ACCEL_Y_GO .001
#define ACCEL_X_STOP .003
#define ACCEL_Y_STOP .003

Hero::Hero(double X, double Y, double VX, double VY, double AX, double AY, int location):Unit(X,Y,VX,VY,AX,AY,location)
{
}

void Hero::collide(Unit* u)
{
}

void Hero::processEvent(double dt)
{
  //Get the keystates
   Uint8 *keystates = SDL_GetKeyState( NULL );

   //Up and down handling
   if( keystates[SDLK_UP] && keystates[SDLK_DOWN] )
    {
      ay = 0;
    }
   else if(keystates[SDLK_UP])
    {
      ay=-ACCEL_Y_GO;
    }
  else if(keystates[SDLK_DOWN])
    {
      ay=ACCEL_Y_GO;
    }

  //Left and right handling
  if( keystates[SDLK_LEFT] && keystates[SDLK_RIGHT] )
    {
      ax = 0;
    }
  else if(keystates[SDLK_LEFT])
    {
      ax = -ACCEL_X_GO;
    }
  else if(keystates[SDLK_RIGHT])
    {
      ax = ACCEL_X_GO;
    }
  // No keys pressed
  if ( (!keystates[SDLK_RIGHT]) && (!keystates[SDLK_LEFT]) && (!keystates[SDLK_DOWN]) && (!keystates[SDLK_UP]) )
    {
      if( abs(vx) <= ACCEL_X_STOP*dt )
	{
	  vx = 0;
	}
      if( abs(vy) <= ACCEL_Y_STOP*dt )
	{
	  vy = 0;
	}
      if( vx > 0 )
	{
	  ax = -ACCEL_X_STOP;
	}
      else if( vx < 0 )
	{
	  ax = ACCEL_X_STOP;
	}
      else
	{
	  ax = 0;
	}
      if( vy > 0 )
	{
	  ay = -ACCEL_Y_STOP;
	}
      else if( vy < 0 )
	{
	  ay = ACCEL_Y_STOP;
	}
      else
	{
	  ay = 0;
	}
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
