/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Sneal header file */

#ifndef SNEAL_H //preprocessing wrappers
#define SNEAL_H

#include <iostream> //include relevant source files and libraries
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"
#include "Stage.h"

class Sneal: public Enemy{ //define the class, inherits from enemy
 public:
  Sneal(double,double,double,double,double,int,Stage*,Hero*); //constructor
  virtual void chase(double,double); //chase function
 private:
  int frame; //private data members
  int state;
  int moving;
  double holdx;
  double holdy;
  double xp1;
  double yp1;
  double xp2;
  double yp2;
  Stage* stage; //pointer to the stage

};

#endif
