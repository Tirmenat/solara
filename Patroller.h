/* FCII Final Project                                                   
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                   
Neal Sheehan                                                                  
Solara
Patroller header file */

#ifndef PATROLLER_H
#define PATROLLER_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"

class Patroller: public Enemy{
 public:
  Patroller(double,double,double,double,double,int,int,Hero*);
  virtual void chase(double,double);
  void patrol();
 private:
  double xp1;
  double yp1;
  double xp2;
  double yp2;
  int state;
};

#endif
