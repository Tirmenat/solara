/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Stage Implementation file */
#include <vector>
#include "Stage.h"
//DOES THIS WORK???

Stage::Stage(x,y)
{	
  units.push_back(new Hero(x,y));
}

void Stage::perform()
{
  for(int i = 0; i < units.size(); i++)
    units[i]->increment();
}

void draw(){

  //drawing the terrain sprites
  for(int i = 0; i<areas.size(); i+=4){
    for(int x = areas[i]; x<areas[i+2]; x+=16){
      for(int y = areas[i+1]; y<areas[i+3]; y+=16){
	//draw correct sprite based on location
	if(x == areas[i]){ //left most column of sprites
	  if(y == areas[i+1]){ //top row of sprites
	    //draw top left corner sprite
	  }
	  else{
	    //draw left edge sprite
	  }
	}
	else if(y == areas[i+1]){//top row of sprites
	  //draw top edge sprite
	}
	else if(x == areas[i+2]-16){//right most column of sprites
	  if(y == areas[i+3]-16){//bottom row of sprites
	    //draw bottom right corner sprite
	  }
	  else{
	    //draw right edge sprite
	  } 
	}
	else if(y == areas[i+3]-16){
	  //draw bottom edge sprite
	}
	else
	  //draw regular sprite
      }
    }
  }
  for(int i = 0; i < units.size(); i++)
    if(inBounds(units[i]->getx()/*minus size?*/, units[i]->gety()))
      units[i]->draw();
}

int Stage::addArea(int a, int b, int c, int d) //adds an area and checks to make sure it is added
{
  //a = topleft x, b = topleft y
  //c = botright x, d = botright y
  areas.push_back(a-a%16); //rounds down to nearest 16 in all of them
  areas.push_back(b-b%16);
  areas.push_back(c-c%16);
  areas.push_back(d-d%16);
  // returns int, false == 0, true == 1
  if(areas[areas.size()-1] != d)
    return false;
  if(areas[areas.size()-2] != c)
    return false;
  if(areas[areas.size()-3] != b)
    return false;
  if(areas[areas.size()-4] != a)
    return false;
  if(areas.size()%4 != 0) //there are not the right number of elements in the areas vector, so return 0
    return false;
  return true;
}

void Stage::addUnit(Unit* spr){
  units.push_back(spr);
}

int Stage::removeUnit(Unit* spr){
  for(int i = 0; i<units.size(); i++)
    {
      if(units[i]->isEqualTo(spr)){
	delete units[i];
	units.erase(units.begin()+i);
	return 1;
      }
    }
  return 0;
}

int Stage::isInBounds(int x, int y){
  int i = 0;
  while(i < areas.size())
    {
      if(x >= areas[i] && x <= areas[i+2])
	if(y >= areas[i+1] && y <= areas[i+3])
	  return true;
      i+=4;
    }
  return false;
  // returns int, false == 0, true == 1
}
