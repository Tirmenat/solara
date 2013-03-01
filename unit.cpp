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
#include "unit.h"

unit::unit(){

}

virtual void unit::setx(double newx){
  x=newx;
}

virtual void unit::sety(double newy){
  y=newy;
}

virtual void unit::setax(double newax){
  ax=newax;
}

virtual void unit::setay(double neway){
  ay=neway;
}

virtual void unit::setvx(double newvx){
  vx=newvx;
}

virtual void unit::setvy(double newvy){
  vy=newvy;
}

virtual float unit::getx(){
  return(x);
}

virtual float unit::gety(){
  return(y);
}

virtual float unit::getax(){
  return(ax);
}

virtual float unit::getay(){
  return(ay);
}

virtual float unit::getvx(){
  return(vx);
}

virtual float unit::getvy(){
  return(vy);
}
