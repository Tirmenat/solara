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

class Enemy: public Unit{
  friend class Patroller;
  friend class Burster;
  friend class Pursuer;
  friend class Shooter;
 public:
  Enemy(double,double,int);
  virtual void collide(Unit* u);
  virtual void draw();
  virtual void chase(double,double);
 private:
  
};

#endif
