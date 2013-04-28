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
  Stage(int,int);
  void perform(double);
  int isInBounds(int, int);
  int addArea(int, int, int, int, int); //returns 1 if area was successfully added, 0 otherwise
  void draw();
  void addUnit(Unit*);
  int removeUnit(Unit*); //returns 1 if unit was successfully removed, 0 otherwise
  void clean_up();
  void clear_screen();
  void drawTitle();
  void adjustUnits(); //keeps units in bounds
 private:
  vector<int> location;
  vector<Unit*> units;
  vector<SDL_Rect> areas; //contains the areas of the stage, stored in rectangle form, 4 points at a time in a vector
  SDL_Rect clip_background[60][22];
  SDL_Surface *background;
  SDL_Surface *title;
  SDL_Surface *screen;
  int size_x;
  int size_y;
  SDL_Surface *load_image( string );
  void apply_surface( int, int, SDL_Surface*, SDL_Surface*, SDL_Rect* );
  bool init();
  bool load_files();
  virtual void set_clips();
};

	#endif
