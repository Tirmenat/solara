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
