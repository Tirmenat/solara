/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Enemy header file */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <iomanip>
#include "Unit.h"
#include "Hero.h"

class Enemy: public Unit{
 public:
  Enemy(double,double,double,int,int,Hero*);
  virtual void collide(Unit*,double);
  virtual void chase(double,double);
  void setmaxv(double);
  double getmaxv();
  void increment(double);
  void draw(SDL_Surface* screen, int xo, int yo);
 private:
  double maxv;
  Hero* hero;
};

#endif
