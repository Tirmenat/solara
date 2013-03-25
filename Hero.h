/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero template file */

#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <iomanip>
#include "unit.h"

class Hero: public Unit{
 public:
  virtual void draw();

 private:

};


#endif
