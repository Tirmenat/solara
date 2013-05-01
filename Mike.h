/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Mike header file */

#ifndef MIKE_H
#define MIKE_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Stage.h"

class Mike: public Enemy{
 public:
  Mike(double,double,double,double,double,int,Stage*,int);
  void chase(double,double);
  void patrol();
 private:
  double xp1;
  double yp1;
  double xp2;
  double yp2;
  int state;
  int statePrev;
  int count;
  Stage* stage;
};

#endif
