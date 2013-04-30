
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
#include "Burster.h"
#include "Mike.h"
#include "Tank.h"
#include "Bullet.h"
#include <ctime>
#include <unistd.h>

#define BASE_VELOCITY 90
#define NUM_BULLETS 5


using namespace std;

/*void fire(Bullet** bullets, Stage* stage, Unit* hero, int dir, int color)
{
  for(int i = 0; i<NUM_BULLETS; i++)
    {
      if(bullets[i] != NULL)
	cout << bullets[i] << endl;
      else
	{
	  bullets[i] = new Bullet(hero, dir, color%2, (color/2)%2, (color/4)%2);
	  stage->addUnit(bullets[i]);
	  return;
	}
      
      
    }
}*/


int main(void)
{
  
  Stage stage_test(100,100);
  // x, y, x size, y size, sprite location
  //stage_test.addArea(50,50,400,400,6);

  // x1, y1, x2, y2, max v, sprite location 
  Patroller patrol_test(100,100,100,200,4*BASE_VELOCITY/5,20);
  Tank tank_test(50,200,3*BASE_VELOCITY/10,13);
  Burster burster_test(200,50,BASE_VELOCITY,17);
  Mike mike_test(50,50,200,50,BASE_VELOCITY,7,&stage_test);
  int curr_bullets = 0;
  
  stage_test.addUnit(&mike_test);
  stage_test.addUnit(&burster_test);
  stage_test.addUnit(&tank_test);
  stage_test.addUnit(&patrol_test);
  stage_test.addArea(100,100,128,144,2);
  stage_test.addArea(448,416,160,32,5);

  //Bullet bullet;
  Sound sounds;
  sounds.load_music("music1");
  sounds.play_music();

  //Bullet* bullets[NUM_BULLETS] = {NULL};
  //Patroller patrol_test2(250,250,100,100,100,5);
  //stage_test.addUnit(&patrol_test2);
  //stage_test.addArea(350-25,350-25,100,100,2);


  // x, y, vx, vy, ax, ay
  Hero hero_test(350,350,200,0,0,0);
  stage_test.addUnit(&hero_test);
  //  Bullet bullet_test(&hero_test,0,0);
  // stage_test.addUnit(&bullet_test);
  //vector<Bullet*> bullets;
  //Bullet not functioning properly yet, will work on fixing

  double dt = 1/60.0;

  clock_t start;

  double duration;

  int next = 0;
  bool quit = false;
  SDL_Event event;
  stage_test.drawTitle("title");
  //  Bullet bullets;
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
		case SDLK_SPACE:
		  //Enter game
		  quit = true;
		  next = 1;
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

  while( quit == false && next==1 ){
    stage_test.drawTitle("slide1");
    if( SDL_PollEvent( &event ) )
      {
	if( event.type == SDL_QUIT )
	  {
	    quit == true;
	  }
	if( event.type == SDL_KEYDOWN )
	  {
	    switch (event.key.keysym.sym)
	      {
	      case SDLK_q:
		quit=true;
		break;
	      case SDLK_SPACE:
		next=2;
		sounds.change_music("music2");
		sounds.play_music();
		stage_test.clear_screen();
	      }
	  }
      }

  }

  while( quit == false && next == 2)
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
		case SDLK_UP:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,0,1,0,0,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_DOWN:		  
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,1,0,1,0,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_LEFT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,2,0,0,1,true));
		      curr_bullets++;
		    }
		  //		  sounds.play_effect("gun");
		  break;
		case SDLK_RIGHT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,3,1,1,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_KP0:
		  sounds.play_effect("croak");
		  break;
		case SDLK_KP1:
		  sounds.play_effect("lasergun");
		  break;
		case SDLK_KP2:
		  sounds.play_effect("woah");
		  break;
		case SDLK_KP3:
		  sounds.play_effect("playerdeath");
		  break;
		case SDLK_KP4:
		  sounds.play_effect("enemydeath");
		  break;
		case SDLK_KP5:
		  sounds.play_effect("ouch");
		  break;
		case SDLK_KP6:
		  sounds.play_effect("boop");
		  break;
		case SDLK_KP7:
		  sounds.play_effect("evillaugh");
		  break;
		}
	    }
	}
      mike_test.patrol();
      burster_test.chase(hero_test.getx(),hero_test.gety());
      tank_test.chase(hero_test.getx(),hero_test.gety());
      patrol_test.chase(hero_test.getx(),hero_test.gety());
      //patrol_test2.chase(hero_test.getx(),hero_test.gety());
      hero_test.processEvent(dt);
      stage_test.perform(dt, &hero_test);
      stage_test.adjustUnits(&curr_bullets);
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
