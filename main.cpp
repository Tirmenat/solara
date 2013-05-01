
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
#include "Shooter.h"
#include <ctime>
#include <unistd.h>
#include <cmath>


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

  // x1, y1, x2, y2, max v, sprite location, health
  Patroller patrol_test(100,100,100,200,4*BASE_VELOCITY/5,20,50);
  Tank tank_test(50,200,3*BASE_VELOCITY/10,13,100);
  tank_test.setHealth(30);
  Burster burster_test(200,50,BASE_VELOCITY,17,50);
  burster_test.setHealth(49);
  Mike mike_test(50,50,200,50,BASE_VELOCITY,7,&stage_test,250);
  mike_test.setHealth(1);
  int curr_bullets = 0;
  Shooter shooter_test(200,200,9,&stage_test);

  stage_test.addUnit(&shooter_test);
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

  int already_west=0;
  int already_south=0;
  int already_east=0;

  //Bullet* bullets[NUM_BULLETS] = {NULL};
  //Patroller patrol_test2(250,250,100,100,100,5);
  //stage_test.addUnit(&patrol_test2);
  //stage_test.addArea(350-25,350-25,100,100,2);


  // x, y, vx, vy, ax, ay
  Hero hero_test(350,350,200,0,0,0,500);
  hero_test.setHealth(350);
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
		stage_test.clear_screen();
	      }
	  }
      }

  }

  while( quit == false && next==2 ){
    stage_test.drawTitle("slide2");
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
		next=3;
		stage_test.clear_screen();
	      }
	  }
      }

  }

  while( quit ==false && next == 3){
    stage_test.drawTitle("slide3");
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
		next=4;
		stage_test.clear_screen();
	      }
	  }
      }

  }

  while( quit ==false && next == 4){
    stage_test.drawTitle("slide4");
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
		next=5;
		stage_test.clear_screen();
	      }
	  }
      }

  }

  while( quit ==false && next == 5){
    stage_test.drawTitle("slide5");
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
	      case SDLK_1:
		next=6;
		if(already_west==1) next=5;
		sounds.change_music("music2");
		sounds.play_music();
		stage_test.clear_screen();
		break;
	      case SDLK_2:
		next=7;
		if(already_south==1) next=5;
		sounds.change_music("music3");
		sounds.play_music();
		stage_test.clear_screen();
		break;
	      case SDLK_3:
		next=8;
		if(already_east==1) next=5;
		sounds.change_music("music4");
		sounds.play_music();
		stage_test.clear_screen();
		break;
	      }
	  }
      }
  }



  //WEST ISLAND
  while( quit == false && next == 6)
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
		      stage_test.addUnit(new Bullet(&hero_test,M_PI/2,1,1,0,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_DOWN:		  
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,3*M_PI/2,0,1,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_LEFT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,M_PI,1,0,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_RIGHT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,0,0,0,0,true));
		      curr_bullets++;
		    }
		  break;
		}
	    }
	}
      shooter_test.chase(hero_test.getx(),hero_test.gety());
      mike_test.chase(hero_test.getx(),hero_test.gety());
      burster_test.chase(hero_test.getx(),hero_test.gety());
      tank_test.chase(hero_test.getx(),hero_test.gety());
      patrol_test.chase(hero_test.getx(),hero_test.gety());
      //patrol_test2.chase(hero_test.getx(),hero_test.gety());
      hero_test.processEvent(dt);
      stage_test.perform(dt, &hero_test);
      stage_test.adjustUnits(&curr_bullets);
      stage_test.checkCollisions(&hero_test);
      stage_test.draw();
      duration = (clock() - start)/((double)CLOCKS_PER_SEC);
     
      if (duration>dt){
	duration=dt;
      }
      usleep((dt-duration)*1000000);
  
    }


      //SOUTH ISLAND
  while( quit == false && next == 7)
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
		      stage_test.addUnit(new Bullet(&hero_test,M_PI/2,1,1,0,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_DOWN:		  
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,3*M_PI/2,0,1,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_LEFT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,M_PI,1,0,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_RIGHT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,0,0,0,0,true));
		      curr_bullets++;
		    }
		  break;
		}
	    }
	}

      mike_test.chase(hero_test.getx(),hero_test.gety());
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



  //EAST ISLAND
  while( quit == false && next == 8)
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
		      stage_test.addUnit(new Bullet(&hero_test,M_PI/2,1,1,0,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_DOWN:		  
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,3*M_PI/2,0,1,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_LEFT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,M_PI,1,0,1,true));
		      curr_bullets++;
		    }
		  break;
		case SDLK_RIGHT:
		  if(curr_bullets<NUM_BULLETS)
		    {
		      stage_test.addUnit(new Bullet(&hero_test,0,0,0,0,true));
		      curr_bullets++;
		    }
		  break;
		}
	    }
	}

      mike_test.chase(hero_test.getx(),hero_test.gety());
      burster_test.chase(hero_test.getx(),hero_test.gety());
      tank_test.chase(hero_test.getx(),hero_test.gety());
      patrol_test.chase(hero_test.getx(),hero_test.gety());
      //patrol_test2.chase(hero_test.getx(),hero_test.gety());
      hero_test.processEvent(dt);
      stage_test.perform(dt, &hero_test);
      stage_test.adjustUnits(&curr_bullets);
      stage_test.draw();
      duration = (clock() - start)/((double)CLOCKS_PER_SEC);
      
      if (duration>.017){
	duration=.017;
      }
      usleep((.017-duration)*1000000);
    }


  sounds.stop_music();
  sounds.clean_up_sound();
  stage_test.clean_up();
}
