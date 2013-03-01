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
  virtual void increment() = 0;
  virtual void draw()=0;
  void setx();
  void sety();
  void setax();
  void setay();
  void setvx();
  void setvy();
  float getx();
  float gety();
  float getax();
  float getay();
  float setvx();
  float setvy();

 private:
  float x;
  float y;
  float ax;
  float ay;
  float vx;
  float vy;

};


#endif
