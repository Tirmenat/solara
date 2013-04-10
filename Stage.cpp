/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Stage Implementation file */
#include <vector>
#include "SDL/SDL.h"
#include "Stage.h"
#include "Hero.h"
//DOES THIS WORK???

Stage::Stage(int x, int y)
{	
  units.push_back(new Hero(x,y,0,0,0,0));
}

void Stage::perform()
{
  for(int i = 0; i < units.size(); i++)
    units[i]->increment();
}

void Stage::draw(){

  //drawing the terrain sprites
  for(int i = 0; i<areas.size(); i++){
    for(int x = areas[i].x; x<areas[i].x+areas[i].w; x+=16){
      for(int y = areas[i].y; y<areas[i].y+areas[i].h; y+=16){
	//draw correct sprite based on location
	if(x == areas[i].x){ //left most column of sprites
	  if(y == areas[i].y){ //top row of sprites
	    //draw top left corner sprite
	  }
	  else{
	    //draw left edge sprite
	  }
	}
	else if(y == areas[i].y){//top row of sprites
	  //draw top edge sprite
	}
	else if(x == areas[i].x+areas[i].w-16){//right most column of sprites
	  if(y == areas[i].y+areas[i].h-16){//bottom row of sprites
	    //draw bottom right corner sprite
	  }
	  else{
	    //draw right edge sprite
	  } 
	}
	else if(y == areas[i].y+areas[i].h-16){
	  //draw bottom edge sprite
	}
	else{
	  
	}
	  //draw regular sprite
      }
    }
  }
  for(int i = 0; i < units.size(); i++)
    if(isInBounds(units[i]->getx()/*minus size?*/, units[i]->gety()))
      units[i]->draw();
}

int Stage::addArea(int x, int y, int w, int h) //adds an area and checks to make sure it is added
{

  SDL_Rect add;
  add.x = x-x%16;
  add.y = y-y%16;
  add.w = w-w%16;
  add.h = h-h%16;
  areas.push_back(add);
  return 1;
/*
  if(add == areas[areas.size()-1])
    return true;
  else
  return false;*/
  
/*
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
    return true;*/
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

int Stage::isInBounds(int x, int y){ //checks if a point is inside any of the areas
  int i = 0;
  while(i < areas.size())
    {
      if(x >= areas[i].x && x <= areas[i].x+areas[i].w)
	if(y >= areas[i].y && y <= areas[i].y+areas[i].h)
	  return true;
      i++;
    }
  return false;
  // returns int, false == 0, true == 1
}
