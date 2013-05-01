#include "Enemy.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 5
#define ACCEL_Y_GO 5
#define ACCEL_X_STOP 1
#define ACCEL_Y_STOP 1
#define _USE_MATH_DEFINES

Enemy::Enemy(double X, double Y, double MAXV, int location, int h,Hero* HERO):Unit(X,Y,MAXV,0,0,location,h)
{
  hero=HERO;
  maxv=MAXV;
}

void Enemy::collide(Unit* u)
{
  
}

void Enemy::setmaxv(double max)
{
  maxv=max;
}

double Enemy::getmaxv()
{
  return (maxv);
}

void Enemy::chase(double herox, double heroy)
{

}

void Enemy::draw(SDL_Surface* screen, int xo, int yo){
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
  // missing = missing health in red
  // inside = red health bar
  inside.x = missing.x = x+xo+1;
  inside.y = missing.y = y+yo-SPRLENGTH/6;
  int currentHealth;
  int totalHealth = SPRWIDTH-2;
  currentHealth = totalHealth*getHealth()/getMaxHealth();
  if(currentHealth==0 && getHealth()>0)
    {
      currentHealth=1;
    }
  inside.w = currentHealth;
  missing.w = totalHealth;
  inside.h = missing.h = SPRLENGTH/6-2;
  //SDL_FillRect( screen, &missing, SDL_MapRGB(screen->format,0,128,255) );
  SDL_FillRect( screen, &inside, SDL_MapRGB(screen->format,255,0,0) );
}

void Enemy::increment(double dt){
  chase(hero->getx(),hero->gety());
  frameShift();
  double angle;
  x=x + vx*dt;
  y=y + vy*dt;
  //  if(moving)                                                                 
  // horizontal velocity                                                         
  if( (vx + ax*dt) >= maxv)
    vx = maxv;
  else if( (vx + ax*dt) <= -maxv)
    vx = -maxv;
  else
    vx = vx + ax*dt;
  // vertical velocity                                                           
  if( (vy + ay*dt) >= maxv)
    vy = maxv;
  else if( (vy + ay*dt) <= -maxv)
    vy = -maxv;
  else
    vy = vy + ay*dt;

  if (sqrt(vx*vx+vy*vy) > maxv){
    angle = atan(vy/vx);
    if (vx < 0 && vy<0){
      vx = -maxv*cos(angle);
      vy = -maxv*sin(angle);
    }
    else if (vx<0 && vy>0){
      vx = -maxv*cos(angle);
      vy = -maxv*sin(angle);
    }
    else{
      frameShift();
      double angle;
      x=x + vx*dt;
      y=y + vy*dt;
      //  if(moving)                                                           
                                                                             
      // horizontal velocity 
      if( (vx + ax*dt) >= maxv)
        vx = maxv;
      else if( (vx + ax*dt) <= -maxv)
        vx = -maxv;
      else
        vx = vx + ax*dt;
      // vertical velocity                                             
                                                                              
      if( (vy + ay*dt) >= maxv)
        vy = maxv;
      else if( (vy + ay*dt) <= -maxv)
        vy = -maxv;
      else
        vy = vy + ay*dt;

      if (sqrt(vx*vx+vy*vy) > maxv){
        angle = atan(vy/vx);
        if (vx < 0 && vy<0){
          vx = -maxv*cos(angle);
          vy = -maxv*sin(angle);
        }
        else if (vx<0 && vy>0){
          vx = -maxv*cos(angle);
          vy = -maxv*sin(angle);
        }      vx = maxv*cos(angle);
	vy = maxv*sin(angle);
      }
    }

  }
}
