#include "Burster.h"
#include "SDL/SDL.h"
#include "Sound.h"
#include <cmath>
#include "Hero.h"

using namespace std;

Burster::Burster(double X, double Y, double maxv, int h, Hero* hero):Enemy(X,Y,maxv,17,h,hero)
{
  moving = 1;
  state=1;
}

void Burster::chase(double herox, double heroy)
{

  double angle;
  double v;
  double vx, vy;
  double x, y;
  x=getx();
  y=gety();
  v=getmaxv();
  //angle = atan ((heroy-y)/(herox-x));

  // moving value goes between 1 and 120
  // state 1 is moving
  // state 2 is holding
  if(moving == 1){
    holdx=herox;
    holdy=heroy;
  }
  angle = atan ((holdy-y)/(holdx-x));
  if(state==1){
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
  else if (state==2){
    vx=0;
    vy=0;
  }
  if (moving==60){
    state=2;
  }
  else if(moving==120){
    moving=0;
    state=1;
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 2) {
    moving=61;
    state=2;
    holdx=herox;
    holdy=heroy;
  }
  moving++;
  setvx(vx);
  setvy(vy);
}
