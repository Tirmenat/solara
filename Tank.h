/* FCII Final Project                                                           
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                     
Neal Sheehan                                                                    
Solara                                                                          
Tank header file */

#ifndef TANK_H
#define PATROLLER_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"

class Patroller: public Enemy{
 public:
  Patroller(double,double,double,in);
  virtual void chase (double,double);
 private:
  
};

#endif
