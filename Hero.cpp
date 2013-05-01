#include "Hero.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 450
#define ACCEL_Y_GO 450
#define ACCEL_X_STOP 600
#define ACCEL_Y_STOP 600

Hero::Hero(double X, double Y, double MAXV, double AX, double AY, int location, int h):Unit(X,Y,MAXV,AX,AY,location,h)
{
  
}

void Hero::collide(Unit* u, double dt)
{
  if(u->isFromHero())
    {
      return;
    }
  //  cout << "collision detected" << endl;
  if(u->isBullet())
    {
      setHealth(getHealth()-1);
      u->setHealth(0);
      //do damage
      //apply effects based on color
    }
  else
    {
      setHealth(getHealth()-10);
      makeInvulnerable();
      //if(vx>0)
      //	setx(getx()-maxv*dt);
      //else
      //	setx(getx()+getvx()*dt);
      //if(vy>0)
      //	sety(gety()-getvy()*dt);
      //else
      //	sety(gety()-getvy()*dt);
      //this->setvx(-this->getvx()*2);
      //this->setvy(-this->getvy()*2);
      //this->setax(0);
      //this->setay(0);
      //u->setx(u->getx()+u->getvx()*dt);
      //u->sety(u->gety()+u->getvy()*dt);
      //u->setx(u->getx()-u->getvx()/10);
      //u->sety(u->gety()-u->getvy()/10);
      //u->setvx(-u->getvx()*2);
      //u->setvy(-u->getvy()*2);
      //u->setax(0);
      //u->setay(0);

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


bool Hero::isFromHero()
{
  return 1;
}


void Hero::draw(SDL_Surface* screen, int xo, int yo){
  // Character and direction
  if(status == UNIT_LEFT)
    {
      apply_surface( x+xo, y+yo, char_left, screen, &clip_char_left[frame]);
    }
  if(status == UNIT_RIGHT)
    {
      apply_surface( x+xo, y+yo, char_right, screen, &clip_char_right[frame]);
    }

  //Unit health
  // border = black outline
  SDL_Rect border, inside, missing;
  border.x = x+xo;
  border.y = y+yo-SPRLENGTH/6-1;
  border.w = SPRWIDTH;
  border.h = SPRLENGTH/6;
  SDL_FillRect( screen, &border, SDL_MapRGB( screen->format,0,0,0) );
  // missing = missing health
  // inside = green health bar
  inside.x = missing.x = x+xo+1;
  inside.y = missing.y = y+yo-SPRLENGTH/6;
  int currentHealth;
  int totalHealth=SPRWIDTH-2;
  currentHealth= totalHealth*getHealth()/getMaxHealth();
  if(currentHealth==0 && getHealth()>0)
    {
      currentHealth=1;
    }
  inside.w = currentHealth;
  missing.w = totalHealth;
  inside.h = missing.h = SPRLENGTH/6-2;
  //SDL_FillRect( screen, &missing, SDL_MapRGB( screen->format,0,128,255) );
  SDL_FillRect( screen, &inside, SDL_MapRGB( screen->format,0,255,0) );
}
