/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Sean header file */

#ifndef SEAN_H
#define SEAN_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"
#include "Stage.h"

class Sean: public Enemy{
 public:
  Sean(double,double,double,double,double,double,double,double,double,int,int,Stage*,Hero*);
  virtual void chase(double,double);
 private:
  Stage* stage;
  int state;
  int moving;
  double xp1;
  double yp1;
  double xp2;
  double yp2;
  double xp3;
  double yp3;
  double xp4;
  double yp4;
};

#endif
