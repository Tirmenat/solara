#include "Enemy.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO .005
#define ACCEL_Y_GO .005
#define ACCEL_X_STOP .001
#define ACCEL_Y_STOP .001
#define _USE_MATH_DEFINES

Enemy::Enemy(double X, double Y, double VX, double VY, double AX, double AY, int location):Unit(X,Y,VX,VY,AX,AY,location)
{
  
}

void Enemy::collide(Unit* u)
{
  
}

void Enemy::draw()
{
  
}

void Enemy::chase(double X, double Y, int dt)
{
  double angle = atan ((Y-y)/(X-x));
  
  if (Y>y) {
    ay = ACCEL_Y_GO * sin(angle)*dt;
  }

  else {
    ay = -ACCEL_Y_GO * sin(angle)*dt;
  }
  

  if (X>x) {
    ax = ACCEL_X_GO * cos(angle)*dt;
  }

  else {
    ax = -ACCEL_X_GO * cos(angle)*dt;
  }

  
}
