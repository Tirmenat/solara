//main program
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Stage.h"
#include "Hero.h"
#include "Enemy.h"

using namespace std;

int main(void)
{
  Stage stage_test(100,100);
  stage_test.addArea(0,0,250,250);
  stage_test.addArea(250,0,250,250);
  stage_test.addArea(150,150,250,250);
  stage_test.addArea(150,350,300,150);

  Enemy enemy_test(100,100,0,0,0,0,20);
  stage_test.addUnit(&enemy_test);

  //Enemy enemy_test2(100,150,0,0,0,0,1);
  //stage_test.addUnit(&enemy_test2);

  Hero hero_test(50,50,0,0,0,0,0);
  stage_test.addUnit(&hero_test);

  int dt = 1;

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
	  if( event.type == SDL_KEYDOWN )
	    {
	      switch (event.key.keysym.sym)
		{
		case SDLK_q:
		  quit=true;
		}
	    }
	}
      double herox = hero_test.getx();
      double heroy = hero_test.gety();
      enemy_test.chase(herox,heroy,dt);
      //enemy_test2.chase(herox,heroy,dt);
      hero_test.processEvent(dt);
      stage_test.perform(dt);
      stage_test.draw();
      //cout << units.getx() << endl << units.gety() << endl << units.getvx() << endl << units.getvy() << endl;
    }

  stage_test.clean_up();
}
