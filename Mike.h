/* FCII Final Project                                                          
Spring 2013                                                                    
Michael Powers                                                                 
Brad Stalcup                                                                   
Sean Murphy                                                                    
Neal Sheehan                                                                   
Solara                                                                         
Mike header file */

#ifndef MIKE_H //preprocessing wrappers
#define MIKE_H

#include <iostream> //include libraries and header files
#include <iomanip>
#include "Enemy.h"
#include "Stage.h"
#include "Hero.h"

class Mike: public Enemy{ //define class mike, which inherits from class enemy
 public: //public functions
  Mike(double,double,double,double,double,int,Stage*,Hero*); //constructor
  void chase(double,double); //chase function
  void patrol(); //patrol function
 private: //private data members
  double xp1; //two control points
  double yp1;
  double xp2;
  double yp2;
  int state; //control variables
  int statePrev;
  int count;
  Stage* stage; //pointer to stage
};

#endif
