#include "Mike.h" //include header files and relevant libraries
#include "Bullet.h"
#include "SDL/SDL.h"
#include <cmath>

using namespace std; //declare std namespace

#define _USE_MATH_DEFINES //define dis macro

Mike::Mike(double XP1, double YP1, double XP2, double YP2, double maxv, int h,Stage* STAGE,Hero* hero):Enemy(XP1,YP1,maxv,7,h,hero){ //constructor for mike that calls Enemy constructor
  xp1 = XP1; //patrol points for mike
  yp1 = YP1;
  xp2 = XP2;
  yp2 = YP2;
  state = 0; //control variables
  count = 0;
  statePrev = 0;
  stage=STAGE; //set the stage
}

void Mike::patrol(){ //patrol function
  double angle=0; //declare local variables
  double vx, vy;
  double x, y;
  double v;
  x=getx(); //retrieve some data from enemy class
  y=gety();
  v=getmaxv();

  //patrols to point 1
  if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))>2 && state==1){ //if we are away from point one, move towards it
    angle = atan ((yp1-y)/(xp1-x)); //calculate the angle
    if (x>=xp1 && y>=yp1){ //apply x and y velocities based on which quadrant we're in
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
      statePrev = 1; //changes state if we reach point 1
      state = 2;
    }
  }
  //patrols to point 2
  else if(sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))>2 && state==0){ //if we are away from point 2 and in state 0, move to point 2
    angle = atan ((yp2-y)/(xp2-x)); //calculate the angle
    if (x>=xp2 && y>=yp2){ //apply x and y velocities based on which quadrant we're in
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
      statePrev = 0; //changes state if we reach point 2
      state = 2;
    }
  }
  // shooting state
  // 5 bullets in a 90 degree arc
  else if(state==2){
    for(int i=0;i<=15;i++){ //16 bullets over 16 frames, to reduce lag
      if(count==i*2){
	stage->addUnit(new Bullet(this,i*M_PI/16+M_PI,0,0,1,false)); //add bullets to the stage class
      }
    }
    count++; //increases frame count
    vx=0; //doesnt move in this state
    vy=0;
    if ( count ==30){ //once count hits 30
      if(statePrev==0){ //sends him to next state depending on previous state
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

//so this function doesnt really do anything, but its here so we can call it in increment in Enemy (needs to be called chase)
void Mike::chase(double herox, double heroy){
  patrol(); //it just calls patrol
}
