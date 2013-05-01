#include "Patroller.h" //including including source files and libraries
#include "SDL/SDL.h"
#include <cmath>
#include "Sound.h"

using namespace std; //std namespace

#define DETECT_RADIUS 150 //macros
#define _USE_MATH_DEFINES

Patroller::Patroller(double XP1, double YP1, double XP2, double YP2, double maxv, int h, Hero* hero):Enemy(XP1,YP1,maxv,19,h,hero){ //constructor for Patroller
  xp1 = XP1; //Instantiate the patrol points
  yp1 = YP1;
  xp2 = XP2;
  yp2 = YP2;
  state = 0; //control variable for states
}

void Patroller::patrol(){  //patrol funciton
  double angle=0; //deafault set angle to 0
  double vx, vy; //declare all local variables
  double x, y;
  double v;
  x=getx(); //retrieve values from enemy
  y=gety();
  v=3*getmaxv()/4;
  

  //patrol at point 1
  if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))>2 && state==1){ //Basically goes back and forth and switches states when it gets to the points
    angle = atan ((yp1-y)/(xp1-x)); //calculate angle
    if (x>xp1 && y>yp1){ //change velocities based on which quadrant we are in
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp1 && y<yp1){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<xp1 && y>yp1){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else if (x<xp1 && angle==0){
      vx=v;
      vy=0;

    }
    else if(x>xp1 && angle==0){
      vx = -v;
      vy=0;
    }
    else{
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    if(sqrt((xp1-x)*(xp1-x)+(yp1-y)*(yp1-y))<=5){
      state = 0; //switches state once we are within 5 pixels of first patrol point
    }
  }
  //patrol at point 2
  if(sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))>2 && state==0){
    angle = atan ((yp2-y)/(xp2-x)); //calculate the angle
    if (x>xp2 && y>yp2){ //switches the velocities based on which quadrant we are in
      vy = -v * sin(angle);
      vx = -v * cos(angle);
    }
    else if(x>xp2 && y<yp2){
      vx = -v*cos(angle);
      vy = -v *sin(angle);
    }
    else if (x<xp2 && y>yp2){
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    else if (x<xp2 && angle==0){
      vx=v;
      vy=0;
      
    }
    else if(x>xp2 && angle==0){
      vx = -v;
      vy=0;
    }
    else {
      vx = v*cos(angle);
      vy = v*sin(angle);
    }
    if (sqrt((xp2-x)*(xp2-x)+(yp2-y)*(yp2-y))<=5){
      state = 1; //switches state once we are withing 5 pixels of second patrol point
    }
    
  }
  setvx(vx); //sets the velocities
  setvy(vy);
}


void Patroller::chase(double herox, double heroy) //chase function that is called every time we increment
{
  double angle; //declare local variables
  double v;
  double vx, vy;
  double x, y;
  double control = 1;
  int soundhelp;
  x=getx(); //get values from Enemy class
  y=gety();
  if(sqrt((herox-x)*(herox-x)+(heroy-y)*(heroy-y))<DETECT_RADIUS){ //if enemy is within Patrollers detection radius, the patroller chases them
    v = getmaxv();
  }
  else { //otherwise the patrol just patrols
    patrol();
    control=0;
  }
  
  //chase when hero comes nearby
  angle = atan ((heroy-y)/(herox-x)); //calculate the angle
  if(control==1){ //if chasing
    if (x>herox && y>heroy){ //adjust velocities based on which quadrant we are in
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
    
    setvx(vx); //set the velocities
    setvy(vy);
  }
}
