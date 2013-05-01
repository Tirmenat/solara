#include "Brad.h"
#include "SDL/SDL.h"
#include <cmath>
#include "Hero.h"
#include "Bullet.h"

using namespace std;

Brad::Brad(double XP1, double YP1, double XP2, double YP2,double maxv, int loc, int h, Stage* STAGE, Hero* hero):Enemy(XP1,YP1,maxv,loc,h,hero)
{
  xp1=XP1;
  yp1=YP1;
  xp2=XP2;
  yp2=YP2;
  moving=1;
  state=1;
  stage=STAGE;
}

void Brad::chase(double herox, double heroy)
{
  double angle;
  double angle2;
  double v;
  double vx, vy;
  double x, y;
  double holdvx, holdvy;
  x=getx();
  y=gety();
  v=getmaxv();
  if(state==1 && moving==1){
    holdx=herox;
    holdy=heroy;
    moving=2;
  }
  //cout<<holdx<<" "<<holdy<<" "<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
  if(state==1 && moving==2){
    angle = atan ((holdy-y)/(holdx-x));
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
  else if(state==2){
    angle=atan ((yp2-y)/(xp2-x));
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
    moving=1;
  }
  if(state==3 && moving==1){
    holdx=herox;
    holdy=heroy;
    moving=2;
  }
  if(state==3 && moving==2){
    angle = atan ((holdy-y)/(holdx-x));
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
  if(state==4){
    angle=atan ((yp1-y)/(xp1-x));
    if (x>xp1 && y>yp1){
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp1 && y<yp1){
      vx = -v * cos(angle);
      vy = -v * sin(angle);
    }
    else if (x<xp1 && y>yp1){
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
  if(sqrt((x-xp2)*(x-xp2)+(y-yp2)*(y-yp2)) <= 5){
    state=3;
    moving=1;
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 3) {
    angle2=atan((heroy-y)/(herox-x));
    if(x>herox){
      angle2 = -angle2 + M_PI;
    }
    else{
      angle2=-angle2;
    }
    Bullet *bullet=new Bullet(this,angle2,0,1,0,false);
    bullet->setvx(bullet->getvx()-vx/2);
    bullet->setvy(bullet->getvy()-vy/2);
    stage->addUnit(bullet);
    //stage->addUnit(new Bullet(this,angle2,0,0,0,false));
    
    if(state==1){
      state=2;
    }
    else if(state==3){
      state=4;
    }
  }
  if(sqrt((x-xp1)*(x-xp1)+(y-yp1)*(y-yp1)) <= 5){
    state=1;
    moving=1;
  }
  setvx(vx);
  setvy(vy);
}
