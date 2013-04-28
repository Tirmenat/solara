#include "Burster.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

Burster::Burster(double X, double Y, double maxv, int loc):Enemy(X,Y,maxv,loc)
{

}

void Burster::chase(double herox, double heroy)
{

  double angle;
  double v;
  double vx, vy;
  double x, y;
  double control = 1;
  x=getx();
  y=gety();
  v=getmaxv();

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
