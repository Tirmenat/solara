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
  Hero(double, double, double, double, double, double);
  virtual void draw();
  virtual void collide(Unit*);
<<<<<<< HEAD
  virtual void increment();
=======
  void processEvent(SDL_Event event)
>>>>>>> 58beb1f9ad4d5a87b9ffcf8222cda1611729d07e

 private:
 double x;
 double y;

};


#endif
