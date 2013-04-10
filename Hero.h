/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero header file */

#ifndef HERO_H
#define HERO_H

#include "Unit.h"

class Hero: public Unit{
 public:
  Hero(double, double, double, double, double, double);
  virtual void draw();
  virtual void collide(Unit*);

 private:
 double x;
 double y;

};


#endif
