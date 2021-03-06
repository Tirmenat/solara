#include "Shooter.h"
#include "SDL/SDL.h"
#include <cmath>
#include "Sound.h"
#include "Bullet.h"

using namespace std;

#define _USE_MATH_DEFINES

Shooter::Shooter(double X, double Y,Stage* STAGE,Hero* hero):Enemy (X,Y,0,9,50,hero){
  x1=X;
  y1=Y;
  count=0;
  stage=STAGE;
}

void Shooter::chase(double herox, double heroy){
  double angle;
  double x;
  double y;
  x=getx();
  y=gety();
  //  herox=herox+8;
  //heroy=heroy+12;
  //consistently shoots in the direction of the Hero
  angle=atan((heroy-y)/(herox-x));
  if(x>herox){
    angle = -angle + M_PI;
  }
  else{
    angle=-angle;
  }
  if (count == 1){
    stage->addUnit(new Bullet(this,angle,0,0,0,false));
  }
  count++;
  if (count==30){
    count=0;
  }
}
