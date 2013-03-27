#include "Stage.h"
//DOES THIS WORK???

Stage::Stage()
{	
	
}

void Stage::perform()
{
	for(int i = 0; i < units.size(); i++)
		units[i].increment();
}

int addArea(int a, int b, int c, int d) //adds an area and checks to make sure it is added
{
	//a = topleft x, b = topleft y
	//c = botright x, d = botright y
	areas.push_back(a);
	areas.push_back(b);
	areas.push_back(c);
	areas.push_back(d);
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

int Stage::removeUnit(Unit spr){
  for(int i = 0; i<units.size(); i++)
  {
	  if(units[i] == spr){  
		  units.remove(units.begin()+i);
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
}