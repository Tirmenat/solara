/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero header file */

#ifndef BULLET_H
#define BULLET_H
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BULLETV 600
#define BULLETLENGTH 9
#define BULLETWIDTH 9
#define BULLETNUM 8

#include "Unit.h"

class Bullet: public Unit{
 public:
  Bullet(Unit*,int,int);
  virtual void draw();
  int getColor();
  virtual bool isBullet();
 private:
  int direction;
  int red;
  int green;
  int blue;
  SDL_Rect clip_bullet[BULLETNUM];
  virtual void set_clips(int);
}



#endif
