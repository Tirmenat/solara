/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Unit Template file */

#ifndef SOLARA_H
#define SOLARA_H

#include <iostream>
#include <iomanip>

class unit{
 public:
  unit();
  virtual void increment();
  virtual void draw()=0;
  virtual void setx(double);
  virtual void sety(double);
  virtual void setax(double);
  virtual void setay(double);
  virtual void setvx(double);
  virtual void setvy(double);
  virtual float getx();
  virtual float gety();
  virtual float getax();
  virtual float getay();
  virtual float setvx();
  virtual float setvy();

 private:
  double x;
  double y;
  double ax;
  double ay;
  double vx;
  double vy;

};


#endif
