#include "Brad.h"
#include "SDL/SDL.h"
#include "Sound.h"
#include <cmath>
#include "Hero.h"

using namespace std;

Brad::Brad(double XP1, double YP1, double XP2, double YP2,double maxv, int loc, int h, Hero* hero):Enemy(XP1,YP1,maxv,loc,h,hero)
{
  xp1=XP1;
  yp1=YP1;
  xp2=XP2;
  yp2=YP2;
  moving=1;
  state=1;
}

void Brad::chase(double herox, double heroy)
{
  double angle;
  double v;
  double vx, vy;
  double x, y;
  x=getx();
  y=gety();
  v=getmaxv();
  if(state==1 && moving==1){
    holdx=herox;
    holdy=heroy;
    moving=2;
  }
  angle = atan ((holdy-y)/(holdx-x));
  if(state==2 && moving==2){
    if (x>holdx && y>holdy){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>holdx && y<holdy){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (x<holdx && y>holdy){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (x<holdx && angle==0){
      vx = v;
      vy = 0;
    }
    else if (x>holdx && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }

  }
  if(state==3){
    angle=atan ((xp2-y)/(xp2-x));
    if (x>xp2 && y>yp2){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp2 && y<yp2){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (x<xp2 && y>yp2){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (x<holdx && angle==0){
      vx = v;
      vy = 0;
    }
    else if (x>holdx && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 2) {
    state=3;
  }
}
