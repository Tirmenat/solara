#include "Hero.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 450
#define ACCEL_Y_GO 450
#define ACCEL_X_STOP 600
#define ACCEL_Y_STOP 600

Hero::Hero(double X, double Y, double VX, double VY, double AX, double AY, int location):Unit(X,Y,VX,VY,AX,AY,location)
{
}

void Hero::collide(Unit* u)
{
  if(u->isBullet())
    {
      //do damage
      //apply effects based on color
    }
  else
    {
      //do damage
      //knock back?
    }
}

void Hero::processEvent(double dt)
{
  //Get the keystates
   Uint8 *keystates = SDL_GetKeyState( NULL );

   //Up and down handling
   if( keystates[SDLK_s] && keystates[SDLK_w] )
    {
      ay = 0;
    }
   else if(keystates[SDLK_w])
    {
      if( vy <= 0)
	ay = -ACCEL_Y_GO;
      else
	ay = -ACCEL_Y_STOP;
    }
   else if(keystates[SDLK_s])
    {
      if(vy>=0)
	ay=ACCEL_Y_GO;
      else
	ay=ACCEL_Y_STOP;
    }

  if ( (!keystates[SDLK_s]) && (!keystates[SDLK_w]) )
    {
      if( abs(vy) <= ACCEL_Y_STOP*dt )
	{
	  vy = 0;
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


  //Left and right handling
  if( keystates[SDLK_a] && keystates[SDLK_d] )
    {
      ax = 0;
    }
  else if(keystates[SDLK_a])
    {
      if( vx <= 0 )
	ax = -ACCEL_X_GO;
      else
	ax = -ACCEL_X_STOP;
    }
  else if(keystates[SDLK_d])
    {
      if(vx >= 0)
	ax = ACCEL_X_GO;
      else
	ax = ACCEL_X_STOP;
    }
  // No keys pressed
 if ( (!keystates[SDLK_d]) && (!keystates[SDLK_a]) )
    {
      
      if( abs(vx) <= ACCEL_X_STOP*dt )
	{
	  vx = 0;
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
