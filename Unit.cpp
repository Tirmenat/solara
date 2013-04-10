/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Unit Implementation file */


#include <iostream>
#include <iomanip>
#include "Unit.h"
#include "SDL/SDL.h"

#define SPRLENGTH 24
#define SPRWIDTH 16
#define UNIT_LEFT 0
#define UNIT_RIGHT 1

Unit::Unit(){
  //x = 0;
  //y = 0;
  clip.x = 0;
  clip.y = 0;
  clip.w = SPRLENGTH;
  clip.h = SPRWIDTH;
  vx = 0;
  vy = 0;
}

Unit::Unit(double X, double Y, double VX, double VY, double AX, double AY){
  // x = X;
  //y = Y;
  clip.x = X;
  clip.y = Y;
  clip.w = SPRWIDTH;
  clip.h = SPRLENGTH;
  vx = VX;
  vy = VY;
  ax = AX;
  ay = AY;
}

// Set Functions
void Unit::setx(double newx){
  clip.x=newx;
  //x=newx;
}

void Unit::sety(double newy){
  clip.y=newy;
  //y=newy;
}

void Unit::setax(double newax){
  ax=newax;
}

void Unit::setay(double neway){
  ay=neway;
}

void Unit::setvx(double newvx){
  vx=newvx;
}

void Unit::setvy(double newvy){
  vy=newvy;
}

// Get Functions
double Unit::getx(){
  return(clip.x);
}

double Unit::gety(){
  return(clip.y);
}

double Unit::getax(){
  return(ax);
}

double Unit::getay(){
  return(ay);
}

double Unit::getvx(){
  return(vx);
}

double Unit::getvy(){
  return(vy);
}

SDL_Rect Unit::getrect(){
  return clip;
}

void Unit::draw(){
	if(vx > 0)
	{
		status = UNIT_LEFT;  //Unit moves left
		frame++; //animation continues
	}
	if(vx < 0)
	{
		status = UNIT_RIGHT; //Unit moves right
		frame++; //animation continues
	}
	else
	{
		frame = 0; //Animation stops at neutral position
	}
	if(frame >= 3)
	{
		frame = 0;
	}
	if(status == UNIT_LEFT){
	  //apply_surface( x, y, unit, screen, &clipsLEFT[frame])
	}
	if(status == UNIT_RIGHT){
	  //apply_surface( x, y, unit, screen, &clipsRight[frane])
	}
}

void Unit::increment(){
	x += vx;
	y += vy;
	vx += ax;
	vy += ay;
}

bool Unit::isEqualTo(Unit* u)
{
  	if(u->getx() != clip.x)
		return false;
	if(u->getx() != clip.y)
		return false;
	if(u->getvx() != vx)
		return false;
	if(u->getvy() != vy)
		return false;
	if(u->getax() != ax)
		return false;
	if(u->getay() != ay)
		return false;
	return true;
}

/*
bool Unit::operator==(Unit* u){ //returns 1 if u and *this are the same
	//right now this isn't foolproof, may have to work on it l
	if(u->getx() != x)
		return false;
	if(u->getx() != y)
		return false;
	if(u->getdx() != dx)
		return false;
	if(u.getdy() != dy)
		return false;
	if(u.getax() != ax)
		return false;
	if(u.getay() != ay)
		return false;
	return true;
	}*/
