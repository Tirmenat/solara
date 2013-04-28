/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero header file */

#ifndef BULLET_H
#define BULLET_H

#include "Unit.h"

class Bullet: public Unit{
 public:
  Bullet(Unit*,int,int);
  virtual void draw();
 private:
  int directionl;
  int x;
  int y;
}



#endif
