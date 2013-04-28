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

class Burster: public Enemy{
 public:
  Burster(double,double,double,int);
  virtual void chase (double,double);
 private:
  int moving;
};




#endif
