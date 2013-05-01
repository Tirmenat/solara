#include "Sneal.h"
#include "SDL/SDL.h"
#include <cmath>
#include "Hero.h"
#include "Bullet.h"

using namespace std;

Sneal::Sneal(double XP1, double YP1, double XP2, double YP2, double maxv, int h, Stage* STAGE, Hero* hero):Enemy(XP1,YP1,maxv,4,h,hero) //constructor
{
  xp1=XP1; //sets the coordinates for the control points
  yp1=YP1;
  xp2=XP2;
  yp2=YP2;
  moving=1; //these are control variables
  state=1;
  stage=STAGE; //pointer to the stage
  frame=1;
}


void Sneal::chase(double herox, double heroy) //chase function for Sneal
{
  double angle; //declare variables
  double angle2;
  double v;
  double vx, vy;
  double x, y;
  double holdvx, holdvy;
  x=getx(); //get values from Enemy class
  y=gety();
  v=getmaxv();
  if(state==1 && moving==1){ //Take in initial coordinates of hero
    holdx=herox; //This is so he doesnt follow neal, but rather go towards where Neal was
    holdy=heroy;
    moving=2;
  }
  if(state==1 && moving==2){ //Starts moving towards the location where Neal was
    angle = atan ((holdy-y)/(holdx-x)); //Calculate the angle
    if (x>holdx && y>holdy){ //Apply velcoity, with if statements to control the output because arctan varies in different quadrants
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
  else if(state==2){ //This state moves from previous location of Neal to second patrol point
    angle=atan ((yp2-y)/(xp2-x)); //Calculate the angle
    if (x>xp2 && y>yp2){ //Apply velocity, with if statements to control the output because arctan varies in different quadrants
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
    moving=1; //sets this control back to 1
    }
  if(state==3 && moving==1){ //so This state will send us from control point 2 back towards neals location
    holdx=herox; //hold the variables
    holdy=heroy;
    moving=2; //change this control
  }
  if(state==3 && moving==2){ //sends us at neals location
    angle = atan ((holdy-y)/(holdx-x)); //calculate angle
    if (x>holdx && y>holdy){ //change velocities based on what quadrant because of how atan works
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
  if(state==4){ //moves from neals previous location back to point 1
    angle=atan ((yp1-y)/(xp1-x)); //calculate angle
    if (x>xp1 && y>yp1){ //change velocities based on quadrant
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
  if(sqrt((x-xp2)*(x-xp2)+(y-yp2)*(y-yp2)) <= 5){ //if he reaches point 2, goes to state 3
    state=3;
    moving=1;
  }
  if(sqrt((x-holdx)*(x-holdx)+(y-holdy)*(y-holdy)) <= 3 && (state==1 || state==3)) {
    vx=0; //if he gets to neals previous location, waits for 30 frames
    vy=0;
    frame++;
    for(double i=3;i<20;i++){ //shoots in a circle aroud him
      if(frame==i){ //16 bullets over 16 frames, so it doesnt lag too much
	stage->addUnit(new Bullet(this,(i-3)*M_PI/8,1,1,1,false)); //makes bullets
      }
    }
    if(state==1 && frame==30){ //if we wait 30 frames send to the correct state based on previous state
      state=2;
      frame=1;
    }
      else if(state==3 && frame==30){
	state=4;
	frame=1;
      }
  }
  if(sqrt((x-xp1)*(x-xp1)+(y-yp1)*(y-yp1)) <= 5){ //if he reaches point 1, goes to state 1
    state=1;
    moving=1;
  }
  setvx(vx); //set velocities;
  setvy(vy);
  
  
}
