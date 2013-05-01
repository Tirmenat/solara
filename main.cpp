
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
#include "Brad.h"
#include "Sean.h"
#include <ctime>
#include <unistd.h>
#include <cmath>


#define BASE_VELOCITY 90


using namespace std;

int main(void)
{
  
  Stage Stageless;
  Stage island[4];
  Hero *hero;

  // x, y, x size, y size, sprite location
  //stage_test.addArea(50,50,400,400,6);
  // x1, y1, x2, y2, max v, sprite location 
 

  //WEST LEVEL DESIGN
  //Patroller patrol00(100,100,100,200,4*BASE_VELOCITY/5,20);
  //Tank tank00(50,200,3*BASE_VELOCITY/10,13);
  //Burster burster00(200,50,BASE_VELOCITY,17);
  //Mike mike(50,50,200,50,BASE_VELOCITY,7,&stage_test);
 
  //Bullet bullet;
  Sound sounds;
  sounds.load_music("music1");
  sounds.play_music();

  //Game Constants
  int currentstage;
  int already_west=0;
  int already_south=0;
  int already_east=0;
  int p2s;
  bool bossdead = false;

  //Bullet constraints
  int r=0;
  int g=0;
  int b=0;

  //Bullet* bullets[NUM_BULLETS] = {NULL};
  //Patroller patrol_test2(250,250,100,100,100,5);
  //stage_test.addUnit(&patrol_test2);
  //stage_test.addArea(350-25,350-25,100,100,2);


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
  Stageless.drawTitle("title");
  //  Bullet bullets;
  //Title screen
  while (quit == false)
    {
      switch(next){
      case 0:  //Title Screen
	p2s=0;
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
		  next = 1;
		  Stageless.clear_screen();
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
      break;

      case 1: //Slide 1
	p2s=0;
	Stageless.drawTitle("slide1");
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
		    Stageless.clear_screen();
		  }
	      }
	  }
	break;

    case 2:  //Slide 2
      p2s=0;
      Stageless.drawTitle("slide2");
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
		  Stageless.clear_screen();
		}
	    }
	} 
      break;

    case 3: //Slide 3
      p2s=0;
      Stageless.drawTitle("slide3");
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
		Stageless.clear_screen();
	      }
	  }
	}
      break;
      case 4: //Slide 4
	p2s=0;
	Stageless.drawTitle("slide4");
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
		    Stageless.clear_screen();
		  }
	      }
	  }	
	break;

      case 5: //Slide 5 - The decision maker
	p2s=0;
	Stageless.drawTitle("slide5");
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
		    Stageless.clear_screen();
		    break;
		  case SDLK_2:
		    next=7;
		    if(already_south==1) next=5;
		    sounds.change_music("music3");
		    sounds.play_music();
		    Stageless.clear_screen();
		    break;
		  case SDLK_3:
		    next=8;
		    if(already_east==1) next=5;
		    sounds.change_music("music4");
		    sounds.play_music();
		    Stageless.clear_screen();
		    break;
		  }
	      }
	  }
	break;
       
      case 6:
	hero = new Hero(350,350,200,0,0,0,500000);
	island[0].addUnit(hero);
	island[0].addUnit(new Mike(200,50,300,50,BASE_VELOCITY,7,&island[0],30,hero));
	island[0].addUnit(new Burster(200,50,BASE_VELOCITY,17,10,hero));
	island[0].addUnit(new Tank(50, 200, 3*BASE_VELOCITY/10,13,100,hero));
	island[0].addUnit(new Patroller(100,100,100,200,BASE_VELOCITY*1.25,20,15,hero));
	island[0].addUnit(new Shooter(200,200,9,&island[0],hero));
	island[0].addUnit(new Brad(120,140,100,350,BASE_VELOCITY*3,18,100,&island[0],hero));
	island[0].addUnit(new Sean(100,200,150,250,200,200,150,150,BASE_VELOCITY,12,100,&island[0],hero));
	island[0].addArea(100,100,128,144,2);
	island[0].addArea(448,416,160,32,5);
	p2s=1;
	currentstage=0;
	break;

      case 7:
	hero = new Hero(75,385,200,0,0,0,100);
	island[1].addUnit(hero);
	island[1].addUnit(new Patroller(100,100,100,350,4*BASE_VELOCITY/5, 20,15,hero));
	island[1].addArea(0,0,500,500,2);
	island[1].addArea(50,50,150,150,3);
	island[1].addArea(500, 0, 600, 150,3);
	island[1].addArea(1000, -100, 100, 100,1);
	island[1].addArea(750,-250, 400, 150, 4);
	island[1].addArea(750,-350,100,100,1);
				      
	p2s=1;
	currentstage=1;
	break;

      case 8:
	p2s=1;
	currentstage=2;
	break;

      case 9:
	p2s=1;
	currentstage=3;
	break;
      case 666:
	p2s=0;
	quit=true;
      }
      if(p2s)
	{
	  bossdead = false;
	  while(bossdead==false && quit ==false){
	    start = clock();
	    //	    cout << "part 2" << endl;
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
			if(island[currentstage].canFire())
			  {
			    island[currentstage].addUnit(new Bullet(hero,M_PI/2,r,g,b,true));
			    sounds.play_effect("gun");
			  }
			break;
		      case SDLK_DOWN:		  
			if(island[currentstage].canFire())
			  {
			    island[currentstage].addUnit(new Bullet(hero,3*M_PI/2,r,g,b,true));
			    sounds.play_effect("gun");
			  }
			break;
		      case SDLK_LEFT:
			if(island[currentstage].canFire())
			  {
			    sounds.play_effect("gun");			  
			    island[currentstage].addUnit(new Bullet(hero,M_PI,r,g,b,true));		    
			  }
			break;
		      case SDLK_RIGHT:
			if(island[currentstage].canFire())
			  {
			    island[currentstage].addUnit(new Bullet(hero,0,r,g,b,true));
			    sounds.play_effect("gun");
			  }
			break;
		      case SDLK_f:
			next = 5;
			bossdead=true;
			island[currentstage].clear_screen();
			break;
		      case SDLK_1: //bullet color control
			//if(already_west)
			  if(r==0) r=1;
			  else r=0;
			break;
		      case SDLK_2:
			//if(already_south)
			  if(g==0) g=1;
			  else g=0;
			break;
		      case SDLK_3:
			//if(already_east)
			  if(b==0) b=1;
			  else b=0;
			break;
		      }
		  }
	      }

	    //mike.patrol();
	    //burster1.chase(hero.getx(),hero.gety());
	    //tank1.chase(hero.getx(),hero.gety());
	    //patrol1.chase(hero_test.getx(),hero_test.gety());
	    //patrol_test2.chase(hero_test.getx(),hero_test.gety());
	    //	    cout << "no here" << endl;
	    //	    cout << "here" << endl;
	    island[currentstage].checkCollisions(hero);
	    if(hero->isDead())
	      {
	        return 0;
	      }
	    if(!(hero->isDead()))
	      {
	    island[currentstage].perform(dt, hero);
	    hero->processEvent(dt);
	    island[currentstage].draw();
	    duration = (clock() - start)/((double)CLOCKS_PER_SEC);
	      
	    if (duration>dt){
	      duration=dt;
	    }
	    usleep((dt-duration)*1000000);
	      }
	  } //End stage loop   
	  
	  if(currentstage==0) already_west = 1;
	  if(currentstage==1) already_south = 1;
	  if(currentstage==2) already_east = 1;
	} 

    } //End main while loop
    sounds.stop_music();
    sounds.clean_up_sound();
    //island[currentstage].clean_up();
}
