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
#include <vector>

using namespace std;

class Stage{
 public:
  Stage(x,y);
  void perform();
  int isInBounds(int, int);
  int addArea(int, int, int, int); //returns 1 if area was successfully added, 0 otherwise
  void draw();
  void addUnit(Unit*);
  int removeUnit(Unit*); //returns 1 if unit was successfully removed, 0 otherwise
 private:
  vector<Unit*> units;
  vector<int> areas; //contains the areas of the stage, stored in rectangle form, 4 points at a time in a vector 
  int size_x;
  int size_y;
};

	#endif
