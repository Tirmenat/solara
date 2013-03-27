/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Unit Implementation file */

#ifndef STAGE_H
#define STAGE_H


#include "Unit.h"



class Stage{
	Stage();
	void perform();
	int isInBounds(int, int);
	void addArea(int, int, int, int);
	void draw();
	void addUnit(Unit, int, int);
	void removeUnit(Unit);
private: 
	int size_x;
	int size_y;

};
	
	#endif
