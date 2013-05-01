/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                  
Solara                                                                         
Burster header file */

#ifndef BURSTER_H
#define BURSTER_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"

class Burster: public Enemy{
 public:
  Burster(double,double,double,int,int,Hero*);
  virtual void chase (double,double);
  string sound(int);
 private:
  int state;
  int moving;
  double holdx;
  double holdy;
};




#endif
