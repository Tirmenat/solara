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
#define BULLETV 300
#define BULLETLENGTH 9
#define BULLETWIDTH 9
#define BULLETNUM 8
//#define MAX_VX 300
//#define MAX_VY 300
//#define MAX_V 300


#include "Unit.h"

class Bullet: public Unit{
 public:
  Bullet();
  Bullet(Unit*,double,int,int,int,bool);
  virtual void draw(SDL_Surface*,int,int);
  int getColor();
  virtual bool isBullet();
  virtual void collide(Unit*);
  virtual bool isFromHero();
 private:
  bool fromHero;
  int direction;
  int red;
  int green;
  int blue;
  SDL_Rect clip_bullet[BULLETNUM];
  SDL_Surface *bullet;
  virtual void set_clips();
  virtual bool load_files();
  virtual SDL_Surface *load_image( string );
  virtual void apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
};



#endif
