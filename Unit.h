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
#include "SDL/SDL.h"

using namespace std;

class Unit{
  friend class Enemy;
  friend class Hero;
 public:
  Unit();
  Unit(double,double,double,double,double,double,int);
  virtual void setx(double);
  virtual void sety(double);
  virtual void setax(double);
  virtual void setay(double);
  virtual void setvx(double);
  virtual void setvy(double);
  // virtual void setv(double);
  virtual double getx();
  virtual double gety();
  virtual double getax();
  virtual double getay();
  virtual double getvx();
  virtual double getvy();
  //  virtual double getv();
  //  virtual SDL_Rect getrect();
  virtual void increment(double);
  virtual void draw( SDL_Surface*);
  virtual bool isEqualTo(Unit*);
  virtual void collide(Unit*) = 0;
  void clean_up();

 private:
  SDL_Rect clip_char_left[11];
  SDL_Rect clip_char_right[11];
  double x;
  double y;
  double vx;
  double vy;
  double ax;
  double ay;
  int frame;  //Used for animation
  int status;  //Used for animation
  int moving; //Used for animation
  virtual SDL_Surface *load_image( string );
  SDL_Surface *char_left;
  SDL_Surface *char_right;
  virtual bool load_files();
  virtual void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
  virtual void set_clips(int);
  virtual void frameShift();
};


#endif
