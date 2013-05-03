#include "Brad.h" //include header files and libraries
#include "SDL/SDL.h"
#include <cmath>
#include "Hero.h"
#include "Bullet.h"

using namespace std; //use std namespace

Brad::Brad(double XP1, double YP1, double XP2, double YP2,double maxv, int h, Stage* STAGE, Hero* hero):Enemy(XP1,YP1,maxv,6,h,hero) //constructor
{
  xp1=XP1; //these are patrol points
  yp1=YP1;
  xp2=XP2;
  yp2=YP2;
  moving=1; //control variables
  state=1;
  stage=STAGE; //pointer to stage
}

void Brad::chase(double herox, double heroy) //chase function
{
  double angle; //declare local variables
  double angle2;
  double v;
  double vx, vy;
  double x, y;
  double holdvx, holdvy;
  x=getx(); //get values from enemy
  y=gety();
  v=getmaxv();
  if(state==1 && moving==1){ // at the beginning, get the location of the hero
    holdx=herox; //store it in holdx and holdy
    holdy=heroy;
    moving=2; //set moving to 2
  }
  if(state==1 && moving==2){ //this is after we get location of hero
    angle = atan ((holdy-y)/(holdx-x)); //calculate angle from point 1 to hero point
    if (x>holdx && y>holdy){ //make velocites based on angle, maxv, and whichever quadrant we are in
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
  else if(state==2){ //if were in state 2
    angle=atan ((yp2-y)/(xp2-x)); //calculate the angle
    if (x>xp2 && y>yp2){ //apply the velocities based on which quadrant we're in
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
    moving=1; //set moving back to 1
  }
  if(state==3 && moving==1){ //if we're in state 3
    holdx=herox; //store hero's  location in these holder variables
    holdy=heroy;
    moving=2; //set moving to 2
  }
  if(state==3 && moving==2){ //Move from location 2 towards wherever hero was
    angle = atan ((holdy-y)/(holdx-x)); //calculate the angle
    if (x>holdx && y>holdy){ //apply velocities based on whichever quadrant we are in
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
  if(state==4){ //if we're in state 4 send us back to point 1
    angle=atan ((yp1-y)/(xp1-x)); //calculate angle
    if (x>xp1 && y>yp1){ //apply velocities based on which quadrant we're in
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
  if(sqrt((x-xp2)*(x-xp2)+(y-yp2)*(y-yp2)) <= 5){ //Moves us from state 2 to 3
    state=3;
    moving=1;
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 3) { //If we reach a point where hero previously was, we shoot bullets towards him
    angle2=atan((heroy-y)/(herox-x));
    if(x>herox){
      angle2 = -angle2 + M_PI;
    }
    else{
      angle2=-angle2;
    }
    Bullet *bullet=new Bullet(this,angle2,0,1,0,false);
    bullet->setvx(bullet->getvx()-vx/2); //Make new bullets, dont account for
    bullet->setvy(bullet->getvy()-vy/2); //brads velocity
    stage->addUnit(bullet);
    //stage->addUnit(new Bullet(this,angle2,0,0,0,false));
    
    if(state==1){ //send us to next state based on previous state
      state=2;
    }
    else if(state==3){
      state=4;
    }
  }
  if(sqrt((x-xp1)*(x-xp1)+(y-yp1)*(y-yp1)) <= 5){ //state 1 from 4
    state=1;
    moving=1;
  }
  setvx(vx); //set the velocities
  setvy(vy);
}
