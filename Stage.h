/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Stage header file */

#ifndef STAGE_H
#define STAGE_H


#include "Unit.h"
#include "SDL/SDL.h"
#include <vector>

using namespace std;

class Stage{
 public:
  Stage();
  void perform(double, Unit*);
  int isInBounds(int, int);
  int addArea(int, int, int, int, int); //returns 1 if area was successfully added, 0 otherwise
  void draw(int,int,int,int,int,int);
  void addUnit(Unit*);
  int removeUnit(Unit*); //returns 1 if unit was successfully removed, 0 otherwise
  void clean_up();
  void clear_screen();
  void drawTitle(string,int,int,int);
  void adjustUnits(); //keeps units in bounds
  int getoffsetx();
  int getoffsety();
  bool checkCollisions(Unit*);
  bool canFire();
  bool isOffScreen(Unit*);
  bool init();
  bool init_fullscreen();
 private:
  int xoffset;
  int yoffset;
  int maxBullets;
  int currBullets;
  vector<int> location;
  vector<Unit*> units;
  vector<SDL_Rect> areas; //contains the areas of the stage, stored in rectangle form, 4 points at a time in a vector
  SDL_Rect clip_background[60][22];
  SDL_Surface *background;
  SDL_Surface *title;
  SDL_Surface *slide1;
  SDL_Surface *slide2;
  SDL_Surface *slide3;
  SDL_Surface *slide4;
  SDL_Surface *slide5;
  SDL_Surface *slide6;
  SDL_Surface *screen;
  int size_x;
  int size_y;
  SDL_Surface *load_image( string );
  void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*, int, int );
  bool load_files();
  virtual void set_clips();
  
};

	#endif
