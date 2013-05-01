#include "Sean.h"
#include "SDL/SDL.h"
#include <cmath>
#include "Hero.h"
#include "Bullet.h"

using namespace std;

Sean::Sean(double XP1, double YP1, double XP2, double YP2, double XP3, double YP3, double XP4, double YP4, double maxv, int loc, int h, Stage* STAGE, Hero* hero):Enemy(XP1,YP1,maxv,loc,h,hero)
{
  xp1=XP1;
  yp1=YP1;
  xp2=XP2;
  yp2=YP2;
  xp3=XP3;
  yp3=YP3;
  xp4=XP4;
  yp4=YP4;
  stage=STAGE;
  state=1;
  moving=1;
}

void Sean::chase(double herox, double heroy)
{
  double angle;
  double v;
  double vx, vy;
  double x, y;
  vx=vy=0;
  x=getx();
  y=gety();
  v=getmaxv();
  if(state==1){
    angle = atan ((yp2-yp1)/(xp2-xp1));
    if (xp1>xp2 && yp1>yp2){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(xp1>xp2 && yp1<yp2){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (xp1<xp2 && yp1>yp2){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (xp1<xp2 && angle==0){
      vx = v;
      vy = 0;
    }
    else if (xp1>xp2 && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }

  }
  else if(state==3){
    angle = atan ((yp2-yp3)/(xp2-xp3));
    if (xp2>xp3 && yp2>yp3){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(xp2>xp3 && yp2<yp3){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (xp2<xp3 && yp2>yp3){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (xp2<xp3 && angle==0){
      vx = v;
      vy = 0;
    }
    else if (xp2>xp3 && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
  }
  else if(state==5){
    angle = atan ((yp4-yp3)/(xp4-xp3));
    if (xp3>xp4 && yp3>yp4){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(xp3>xp4 && yp3<yp4){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (xp3<xp4 && yp3>yp4){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (xp3<xp4 && angle==0){
      vx = v;
      vy = 0;
    }
    else if (xp3>xp4 && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
  }
  else if(state==7){
    angle = atan ((yp4-yp1)/(xp4-xp1));
    if (xp4>xp1 && yp4>yp1){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(xp4>xp1 && yp4<yp1){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (xp4<xp1 && yp4>yp1){
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
    else if (xp4<xp1 && angle==0){
      vx = v;
      vy = 0;
    }
    else if (xp4>xp1 && angle==0){
      vx = -v;
      vy = 0;
    }
    else{
      vx = v * cos(angle);
      vy = v * sin(angle);
    }
  }

  if(sqrt((x-xp2)*(x-xp2)+(y-yp2)*(y-yp2)) <= 4 && state==1){
    state=2;
  }
  if(sqrt((x-xp3)*(x-xp3)+(y-yp3)*(y-yp3)) <= 4 && state==3){
    state=4;
  }
  if(sqrt((x-xp4)*(x-xp4)+(y-yp4)*(y-yp4)) <= 4 && state==5){
    state=6;
  }
  if(sqrt((x-xp1)*(x-xp1)+(y-yp1)*(y-yp1)) <= 4 && state==7){
    state=8;
  }
  if(state==2 || state==4 || state==6 || state==8){
    moving++;
    if(state==2){
      if(moving==30){
	state=3;
	moving=1;
      }
    }
    else if(state==4){
	if(moving==30){
	  state=5;
	  moving=1;
	}
    }
    else if(state==6){
      if(moving==30){
	state=7;
	moving=1;
      }
    }
    else if(state==8){
      if(moving==30){
	state=1;
	moving=1;
      }
    }
  }
  setvx(vx);
  setvy(vy);
}
