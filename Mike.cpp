#include "Mike.h"
#include "Bullet.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std;

#define _USE_MATH_DEFINES

Mike::Mike(double XP1, double YP1, double XP2, double YP2, double maxv, int h,Stage* STAGE,Hero* hero):Enemy(XP1,YP1,maxv,7,h,hero){
  xp1 = XP1;
  yp1 = YP1;
  xp2 = XP2;
  yp2 = YP2;
  state = 0;
  count = 0;
  statePrev = 0;
  stage=STAGE;
}

void Mike::patrol(){
  double angle=0;
  double vx, vy;
  double x, y;
  double v;
  x=getx();
  y=gety();
  v=getmaxv();

  //patrols to point 1
  if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))>2 && state==1){
    angle = atan ((yp1-y)/(xp1-x));
    if (x>=xp1 && y>=yp1){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>=xp1 && y<=yp1){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<=xp1 && y>=yp1){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else {
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))<=5){
      statePrev = 1;
      state = 2;
    }
  }
  //patrols to point 2
  else if(sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))>2 && state==0){
    angle = atan ((yp2-y)/(xp2-x));
    if (x>=xp2 && y>=yp2){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>=xp2 && y<=yp2){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<=xp2 && y>=yp2){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else{
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    if (sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))<=5){
      statePrev = 0;
      state = 2;
    }
  }
  // shooting state
  // 5 bullets in a 90 degree arc
  else if(state==2){
    for(int i=0;i<=15;i++){
      if(count==i*2){
	stage->addUnit(new Bullet(this,i*M_PI/16+M_PI,0,0,1,false));
      }
    }
    /*if (count==5){
      stage->addUnit(new Bullet(this,5*M_PI/4,0,0,1,false));
    }
    else if(count==10){
      stage->addUnit(new Bullet(this,22*M_PI/16,0,0,1,false));
    }

    else if(count==15){
      stage->addUnit(new Bullet(this,3*M_PI/2,0,0,1,false));
    }
    else if (count==20){
      stage->addUnit(new Bullet(this,26*M_PI/16,0,0,1,false));
    }
    else if(count==25){
      stage->addUnit(new Bullet(this,7*M_PI/4,0,0,1,false));
      }*/
    count++;
    vx=0;
    vy=0;
    if ( count ==30){
      if(statePrev==0){
	state=1;
	count=0;
      }
      else if(statePrev==1){
	state=0;
	count=0;
      }
    }
  }
  setvx(vx);
  setvy(vy);
}

void Mike::chase(double herox, double heroy){
  patrol();
}
