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

Unit::Unit(){

}

virtual void Unit::setx(double newx){
  x=newx;
}

virtual void Unit::sety(double newy){
  y=newy;
}

virtual void Unit::setax(double newax){
  ax=newax;
}

virtual void Unit::setay(double neway){
  ay=neway;
}

virtual void Unit::setvx(double newvx){
  vx=newvx;
}

virtual void Unit::setvy(double newvy){
  vy=newvy;
}

virtual float Unit::getx(){
  return(x);
}

virtual float Unit::gety(){
  return(y);
}

virtual float Unit::getax(){
  return(ax);
}

virtual float Unit::getay(){
  return(ay);
}

virtual float Unit::getvx(){
  return(vx);
}

virtual float Unit::getvy(){
  return(vy);
}

virtual void Unit::increment(){
	x += vx;
	y += vy;
	vx += ax;
	vy += ay;
}
