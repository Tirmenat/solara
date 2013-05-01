/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Tank header file */

#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"

class Tank: public Enemy{
 public:
  Tank(double,double,double,int,Hero*);
  virtual void chase (double,double);
 private:
};

#endif
