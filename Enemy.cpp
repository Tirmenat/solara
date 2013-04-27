#include "Enemy.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 5
#define ACCEL_Y_GO 5
#define ACCEL_X_STOP 1
#define ACCEL_Y_STOP 1
#define _USE_MATH_DEFINES

Enemy::Enemy(double X, double Y, int location):Unit(X,Y,0,0,0,0,location)
{
  
}

void Enemy::collide(Unit* u)
{
  
}

void Enemy::draw()
{
  
}

void Enemy::chase(double herox, double heroy)
{
  double angle;
  double v;
  if(sqrt((herox-x)*(herox-x)+(heroy-y)*(heroy-y))<100)
    v = 150;
  else
    v = 0;
  
  angle = atan ((heroy-y)/(herox-x));
  
  
  if (x>herox && y>heroy){
    vy = -v * sin(angle);
    vx = -v * cos(angle);
  }
  else if(x>herox && y<heroy){
    vx = -v*cos(angle);
    vy = -v *sin(angle);
  }
  else if (x<herox && y>heroy){
    vx = v*cos(angle);
    vy = v*sin(angle);
  }
  else{
    vx = v*cos(angle);
    vy = v*sin(angle);
  }
  
  
  
  //    vy = -v * sin(angle);
  //vx = -v * cos(angle);
  
}
