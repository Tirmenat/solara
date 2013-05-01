/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Sneal header file */

#ifndef SNEAL_H
#define SNEAL_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"
#include "Stage.h"

class Sneal: public Enemy{
 public:
  Sneal(double,double,double,double,double,int,Stage*,Hero*);
  virtual void chase(double,double);
 private:
  int frame;
  int state;
  int moving;
  double holdx;
  double holdy;
  double xp1;
  double yp1;
  double xp2;
  double yp2;
  Stage* stage;

};

#endif
