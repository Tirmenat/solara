#include "Enemy.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 5
#define ACCEL_Y_GO 5
#define ACCEL_X_STOP 1
#define ACCEL_Y_STOP 1
#define _USE_MATH_DEFINES

Enemy::Enemy(double X, double Y, double MAXV, int location, int h):Unit(X,Y,MAXV,0,0,location,h)
{
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
  double angle;
  double v;
  if(sqrt((herox-x)*(herox-x)+(heroy-y)*(heroy-y))<100)
    v = 100;
  else
    v = 0;
  
  angle = atan ((heroy-y)/(herox-x));
  
  
  if (x>herox && y>heroy){
    vy = -v * sin(angle);
    vx = -v * cos(angle);
  }
  else if(x>herox && y<heroy){
    vx = -v*cos(angle);
    vy = -v*sin(angle);
  }
  else if (x<herox && y>heroy){
    vx = v*cos(angle);
    vy = v*sin(angle);
  }
  else if (x<herox && angle==0){
    vx = v;
    vy = 0;
  }
  else if (x>herox && angle==0){
    vx = -v;
    vy = 0;
  }
  else{
    vx = v*cos(angle);
    vy = v*sin(angle);
  }
  
  
  
  //    vy = -v * sin(angle);
  //vx = -v * cos(angle);
  
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
  // inside = purple health bar
  inside.x = missing.x = x+xo+1;
  inside.y = missing.y = y+yo-SPRLENGTH/6;
  int currentHealth;
  int totalHealth=SPRWIDTH-2;
  currentHealth= totalHealth*getHealth()/getMaxHealth();
  inside.w = currentHealth;
  missing.w = totalHealth;
  inside.h = missing.h = SPRLENGTH/6-2;
  SDL_FillRect( screen, &missing, SDL_MapRGB( screen->format,255,0,0) );
  SDL_FillRect( screen, &inside, SDL_MapRGB( screen->format,128,0,255) );
}
