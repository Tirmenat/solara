#include "Patroller.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define ACCEL_X_GO 5
#define ACCEL_Y_GO 5
#define ACCEL_X_STOP 1
#define ACCEL_Y_STOP 1
#define _USE_MATH_DEFINES

Patroller::Patroller(double XP1, double YP1, double XP2, double YP2, int loc):Enemy(XP1,YP1,loc){
  xp1 = XP1;
  yp1 = YP1;
  xp2 = XP2;
  yp2 = YP2;
  location = loc;
}

void Patroller::patrol(){
  double angle=0;
  double vx, vy;
  double x, y;
  double v;
  x=getx();
  y=gety();
  v=150;
  cout<<vx<<" "<<vy<<endl;
  
  angle = atan ((yp1-y)/(xp1-x));

  if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))>2){
    if (x>xp1 && y>yp1){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp1 && y<yp1){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<xp1 && y>yp1){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else{
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
  }
  else{
    vx=0;
    vy=0;
  }
  setvx(vx);
  setvy(vy);
}


void Patroller::chase(double herox, double heroy)
{
  double angle;
  double v;
  double vx, vy;
  double x, y;
  double control = 1;
  x=getx();
  y=gety();
  if(sqrt((herox-x)*(herox-x)+(heroy-y)*(heroy-y))<100){
    v = 150;
  }
  else {
    patrol();
    control=0;
  }
  
  angle = atan ((heroy-y)/(herox-x));
  if(control==1){
  if (x>herox && y>heroy){
    vy = -v * sin(angle);
    vx = -v * cos(angle);
  }
  else if(x>herox && y<heroy){
    vx = -v * cos(angle);
    vy = -v * sin(angle);
  }
  else if (x<herox && y>heroy){
    vx = v * cos(angle);
    vy = v * sin(angle);
  }
  else{
    vx = v * cos(angle);
    vy = v * sin(angle);
  }
  
  setvx(vx);
  setvy(vy);
  }
  cout<<x<<" "<<y<<endl;
}
