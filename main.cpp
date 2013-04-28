//main program
#include <iostream>
#include <string>
#include "string.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Stage.h"
#include "Hero.h"
#include "Enemy.h"
#include "Sound.h"
#include "Patroller.h"
#include <ctime>
#include <unistd.h>

using namespace std;

int main(void)
{
  Stage stage_test(100,100);
  stage_test.addArea(0,0,250,250);
  stage_test.addArea(250,0,250,250);
  stage_test.addArea(150,150,250,250);
  stage_test.addArea(150,350,300,150);

  Patroller patrol_test(100,100,0,0,150,20);
  stage_test.addUnit(&patrol_test);

  Sound sounds;
  sounds.load_music("music1");
  sounds.play_music();

  Patroller patrol_test2(250,250,0,0,100,5);
  stage_test.addUnit(&patrol_test2);

  Hero hero_test(50,50,0,0,0,0,0);
  stage_test.addUnit(&hero_test);

  double dt = 1/60.0;

  clock_t start;

  double duration;

  bool next = false;
  bool quit = false;
  SDL_Event event;
  stage_test.drawTitle();

  //Title screen
  while (quit == false)
    {

      //While there's an event to handle
      while (SDL_PollEvent (&event))
	{


	  if (event.type == SDL_KEYDOWN)
	    {
	      //Set the proper message surface
	      switch (event.key.keysym.sym)
		{
		  //Quit game
		case SDLK_q:
		  quit = true;
		  break;
		case SDLK_k:
		  //Enter game
		  sounds.change_music("music5");
		  sounds.play_music();
		  quit = true;
		  next = true;
		  break;
		}
	    }

	  //If the user has Xed out the window
	  else if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
	    }
	}
    }

  stage_test.clear_screen();
  quit = false;
  //In-game screen
  while( quit == false && next == true)
    {
      start = clock();
      //      int time = time();
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
		  break;
		case SDLK_w:
		  sounds.play_effect("gun");
		  break;
		case SDLK_e:
		  sounds.play_effect("croak");
		  break;
		case SDLK_d:
		  sounds.play_effect("lasergun");
		  break;
		case SDLK_a:
		  sounds.play_effect("woah");
		  break;
		}
	    }
	}
      patrol_test.chase(hero_test.getx(),hero_test.gety());
      patrol_test2.chase(hero_test.getx(),hero_test.gety());
      //enemy_test2.chase(herox,heroy);
      hero_test.processEvent(dt);
      stage_test.perform(dt);
      stage_test.adjustUnits();
      stage_test.draw();
      duration = (clock() - start)/((double)CLOCKS_PER_SEC);
     
      if (duration>.016){
	duration=.016;
      }
      usleep((.017-duration)*1000000);
    }
  sounds.stop_music();
  sounds.clean_up_sound();
  stage_test.clean_up();
}
