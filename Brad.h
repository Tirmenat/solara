/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Brad header file */

#ifndef BRAD_H
#define BRAD_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"

class Brad: public Enemy{
 public:
  Brad(double,double,double,double,double,int,int,Hero*);
  virtual void chase (double,double);
  string sound(int);
 private:
  int state;
  int moving;
  double holdx;
  double holdy;
  double xp1;
  double yp1;
  double xp2;
  double yp2;
};




#endif
