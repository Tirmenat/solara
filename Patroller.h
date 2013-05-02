/* FCII Final Project                                                   
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                   
Neal Sheehan                                                                  
Solara
Patroller header file */

#ifndef PATROLLER_H //preprocessing wrappers
#define PATROLLER_H

#include <iostream> //include header files and libraries
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"

class Patroller: public Enemy{ //declare class patroller, which inherits from enemy class
 public: //public functions
  Patroller(double,double,double,double,double,int,Hero*); //constructor
  virtual void chase(double,double); //chse function
  void patrol(); //patrol function
 private: //private data members
  double xp1; //patrol points
  double yp1;
  double xp2;
  double yp2;
  int state; //state control variable
};

#endif
