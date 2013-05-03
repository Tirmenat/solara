/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Brad header file */

#ifndef BRAD_H //Preprocessing wrappers
#define BRAD_H

#include <iostream> //Include header files and libraries
#include <iomanip>
#include "Enemy.h"
#include "Hero.h"
#include "Stage.h"

class Brad: public Enemy{ //declaration of class
 public: //public functions
  Brad(double,double,double,double,double,int,Stage*,Hero*); //constructor
  virtual void chase (double,double); //chase function
 private: //private data members
  int state; // state control variables
  int moving;
  double holdx; //hold variables
  double holdy;
  double xp1; //2 "patrol" points
  double yp1;
  double xp2;
  double yp2;
  Stage* stage; //stage pointer
};




#endif
