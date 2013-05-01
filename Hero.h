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
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

class Hero: public Unit{
 public:
  Hero(double, double, double, double, double, int, int);
  virtual void collide(Unit*);
  void processEvent(double);
};


#endif
