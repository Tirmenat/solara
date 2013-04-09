/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Unit header file */

#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <iomanip>

class Unit{
 public:
  Unit();
  Unit(int,int);
  virtual void setx(double);
  virtual void sety(double);
  virtual void setax(double);
  virtual void setay(double);
  virtual void setvx(double);
  virtual void setvy(double);
  virtual double getx();
  virtual double gety();
  virtual double getax();
  virtual double getay();
  virtual double getvx();
  virtual double getvy();
  virtual SDL_Rect getrect();
  virtual void increment();
  virtual void draw() = 0;
  virtual bool isEqualTo(Unit*);
  virtual void collide(Unit*) = 0;

 private:
  SDL_Rect clip;
  double x;
  double y;
  double ax;
  double ay;
  double vx;
  double vy;
<<<<<<< HEAD
  
=======
  int frame;  //Used for animation
  int status;  //Used for animation
>>>>>>> 8915434441add2a972453853bd163329174c0c0b

};


#endif
