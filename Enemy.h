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
 public:
  Enemy(double,double,double,int);
  virtual void collide(Unit* u);
  virtual void chase(double,double);
  void setmaxv(double);
  double getmaxv();

 private:
  double maxv;
};

#endif
