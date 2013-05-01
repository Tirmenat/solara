/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Shooter header file */

#ifndef SHOOTER_H
#define SHOOTER_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"
#include "Stage.h"

class Shooter: public Enemy{
 public:
  Shooter(double,double,int,Stage*,Hero*);
  void chase(double,double);
 private:
  double x1;
  double y1;
  double count;
  Stage* stage;
};



#endif
