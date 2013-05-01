#include "Burster.h"
#include "SDL/SDL.h"
#include "Sound.h"
#include <cmath>

using namespace std;

Burster::Burster(double X, double Y, double maxv, int loc):Enemy(X,Y,maxv,loc)
{
  moving = 0;
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
  if(moving == 1){
    holdx=herox;
    holdy=heroy;
  }
  angle = atan ((holdy-y)/(holdx-x));
  if(moving>=0 && moving<60){
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
  else if (moving>=60 && moving < 120){
    vx=0;
    vy=0;
  }
  else if (moving==120){
    moving=0;
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 2) {
    moving=60;
    holdx=herox;
    holdy=heroy;
  }
  moving++;
  setvx(vx);
  setvy(vy);
}
