//main program
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Stage.h"
#include "Hero.h"

using namespace std;

int main(void)
{
  Stage stages(100,100);
  stages.addArea(0,0,250,250);
  stages.addArea(250,0,250,250);
  stages.addArea(150,150,250,250);

  Hero units(50,50,1.0,1.0,1.0,1.0,0);
  stages.addUnit(&units);

  units.setax(.25);

  bool quit = false;
  SDL_Event event;
  //While the user hasn't quit
  while( quit == false )
    {
      //If there's an event
      if( SDL_PollEvent( &event ) )
	{
	  //If user X's out of windows
	  if( event.type == SDL_QUIT )
	    {
	      quit = true;
	    }
	}
      stages.draw();
    }

  stages.clean_up();

  cout << units.getx() << endl << units.gety() << endl << units.getvx() << endl << units.getvy() << endl; //testcode
}
