#include "Patroller.h"
#include "SDL/SDL.h"
#include <cmath>
#include "Sound.h"

using namespace std;

#define _USE_MATH_DEFINES

Patroller::Patroller(double XP1, double YP1, double XP2, double YP2, double maxv, int loc, int h):Enemy(XP1,YP1,maxv,loc,h){
  xp1 = XP1;
  yp1 = YP1;
  xp2 = XP2;
  yp2 = YP2;
  state = 0;
}

void Patroller::patrol(){
  double angle=0;
  double vx, vy;
  double x, y;
  double v;
  x=getx();
  y=gety();
  v=3*getmaxv()/4;
  

  if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))>2 && state==1){
    angle = atan ((yp1-y)/(xp1-x));
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
    if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))<=5){
      state = 0;
    }
  }
  else if(sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))>2 && state==0){
    angle = atan ((yp2-y)/(xp2-x));
    if (x>xp2 && y>yp2){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp2 && y<yp2){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<xp2 && y>yp2){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else{
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    if (sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))<=5){
      state = 1;
    }
    
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
  int soundhelp;
  x=getx();
  y=gety();
  if(sqrt((herox-x)*(herox-x)+(heroy-y)*(heroy-y))<100){
    v = getmaxv();
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
    else if (x<herox && angle==0){
      vx = v;
      vy = 0;
    }
    else if (x>herox && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    
    setvx(vx);
    setvy(vy);
  }
}
