
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
#include "Sneal.h"
#include <ctime>
#include <unistd.h>
#include <cmath>


#define BASE_VELOCITY 90


using namespace std;

int main(void)
{
  //Screen alternations
  int screen_state=0;

  //Class instantiation
  Stage Stageless;
  Stage island[4];
  string screens[15];
  Hero *hero;
  Mike *mike;
  Brad *brad;
  Sean *sean;
  Sneal *sneal;
  int *bosshealth;

  //Screens strings

  //disable mouse cursor
  SDL_ShowCursor(SDL_DISABLE);

  // x, y, x size, y size, sprite location
  //stage_test.addArea(50,50,400,400,6);
  // x1, y1, x2, y2, max v, sprite location 
 
  Sound sounds;
  sounds.load_music("music1");
  sounds.play_music();

  //Game Constants
  int currentstage=0;
  int already_west=0;
  int already_south=0;
  int already_east=0;
  int p2s;
  int help;
  bool bossdead = false;

  //Bullet constraints
  int r=0;
  int g=0;
  int b=0;

  //Time variables
  double dt = 1/60.0;
  clock_t start;
  double duration;

  //First State
  int next = 0;

  bool quit = false;
  SDL_Event event;
  //  Bullet bullets;
  //Title screen
  while (quit == false)
    {
      switch(next)
	{
	case 0:  //Title Screen
	  Stageless.drawTitle("title",0,0,0);
	  p2s=0;
	  //While there's an event to handle
	  while (SDL_PollEvent (&event))
	    {
	      if (event.type == SDL_QUIT)
		{
		  //Quit the program
		  quit = true;
		  break;
		}
	      else if (event.type == SDL_KEYDOWN)
		{
		  //Set the proper message surface
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      //Quit game
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      //Enter game
		      next++;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      //alternate between fullscreen
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("title",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("title",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }  
	  break;
	  
	case 1: //Slide 1
	  p2s=0;
	  Stageless.drawTitle("slide1",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=2;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slide1",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slide1",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }
	  break;
	  
	case 2:  //Slide 2
	  p2s=0;
	  Stageless.drawTitle("slide2",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=3;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slide1",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slide1",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }
	  break;
	  
	case 3: //Slide 3
	  p2s=0;
	  Stageless.drawTitle("slide3",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {	      
	      quit == true;
	      break;
	    }
	  else if( event.type == SDL_KEYDOWN )
	    {
	      switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		  quit = true;
		  Stageless.init();
		  break;
		case SDLK_SPACE:
		  next=4;
		  Stageless.clear_screen();
		  break;
		case SDLK_f:
		  if(screen_state==0)
		    {
		      Stageless.init_fullscreen();
		      Stageless.drawTitle("slide3",0,0,0);
		      screen_state=1;
		    }
		  else
		    {
		      Stageless.init();
		      Stageless.drawTitle("slide3",0,0,0);
		      screen_state=0;
		    }
		  break;
		}
	    }
	  break;

	case 4: //Slide 4
	  p2s=0;
	  Stageless.drawTitle("slide4",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=5;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slide4",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slide4",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }	
	  break;

	case 10:   //Slide after defeating Mike
	  p2s=0;
	  Stageless.drawTitle("slidemike",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=5;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slidemike",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slidemike",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }		  
	  break;

	case 11:  //Slide state after defeating Brad
	  p2s=0;
	  Stageless.drawTitle("slidebrad",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=5;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slidebrad",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slidebrad",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }		  
	  break;

	case 12:   //slide after defeating Sean
	  p2s=0;
	  Stageless.drawTitle("slidesean",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      next=5;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slidesean",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slidesean",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }		  
	  break;

	case 13:  //Slide after defeating neal
	  p2s=0;
	  Stageless.drawTitle("slidesneal",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_SPACE:
		      sounds.change_music("music6");
		      sounds.play_music();
		      next=14;
		      Stageless.clear_screen();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("slidesneal",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("slidesneal",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }		  
	  break;

	case 14:   //End game slide
	  p2s=0;
	  Stageless.drawTitle("youwin",0,0,0);
	  if( SDL_PollEvent( &event ) )
	    {
	      if( event.type == SDL_QUIT )
		{
		  quit == true;
		  break;
		}
	      else if( event.type == SDL_KEYDOWN )
		{
		  switch (event.key.keysym.sym)
		    {
		    case SDLK_ESCAPE:
		      quit = true;
		      Stageless.init();
		      break;
		    case SDLK_f:
		      if(screen_state==0)
			{
			  Stageless.init_fullscreen();
			  Stageless.drawTitle("youwin",0,0,0);
			  screen_state=1;
			}
		      else
			{
			  Stageless.init();
			  Stageless.drawTitle("youwin",0,0,0);
			  screen_state=0;
			}
		      break;
		    }
		}
	    }		  
	  break;

	case 5: //Slide 5 - The decision maker
	  p2s=0;
	  if(already_west && already_east && already_south) //Pre North Island
	    {
	      Stageless.drawTitle("slide6",0,0,0);
	      if( SDL_PollEvent( &event ) )
		{
		  if (event.type == SDL_QUIT )
		    {
		      quit == true;
		      break;
		    }
		  else if (event.type == SDL_KEYDOWN )
		    {
		      switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			  quit = true;
			  Stageless.init();
			  break;
			case SDLK_4:
			  next=9;
			  sounds.change_music("music5");
			  sounds.play_music();
			  Stageless.clear_screen();
			  break;
			case SDLK_f:
			  if(screen_state==0)
			    {
			      Stageless.init_fullscreen();
			      Stageless.drawTitle("slide6",0,0,0);
			      screen_state=1;
			    }
			  else
			    {
			      Stageless.init();
			      Stageless.drawTitle("slide6",0,0,0);
			      screen_state=0;
			    }
			  break;
			}
		    }
		}
	    }
	  else      //Pre Other Islands
	    {
	      Stageless.drawTitle("slide5",already_west,already_south,already_east);
	      if( SDL_PollEvent( &event ) )
		{
		  if( event.type == SDL_QUIT )
		    {
		      quit == true;
		      break;
		    }
		  if( event.type == SDL_KEYDOWN )
		    {
		      switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			  quit = true;
			  Stageless.init();
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
			case SDLK_f:
			  if(screen_state==0)
			    {
			      Stageless.init_fullscreen();
			      Stageless.drawTitle("slide5",already_west,already_south,already_east);
			      screen_state=1;
			    }
			  else
			    {
			      Stageless.init();
			      Stageless.drawTitle("slide5",already_west,already_south,already_east);
			      screen_state=0;
			    }
			  break;
			}
		    }
		}
	    }	
	  break;
	
	case 6:  //Head to West Island Level and design that level
	  hero = new Hero(25,25,200,0,0,0,5000);
	  mike = new Mike(1100,375,1225,375,2*BASE_VELOCITY,150,&island[0],hero);
	  island[0].addUnit(hero);
	  island[0].addUnit(mike);
	  island[0].addUnit(new Shooter(1100,400,&island[0],hero));
	  island[0].addUnit(new Shooter(1225,400,&island[0],hero));
	  island[0].addUnit(new Patroller(700,350 ,400,350,5*BASE_VELOCITY/3,80,hero));
	  island[0].addUnit(new Patroller(400,450,700,450,5*BASE_VELOCITY/3,80,hero));
	  island[0].addUnit(new Patroller(400,550,700,1000,5*BASE_VELOCITY/3,80,hero));
	  island[0].addUnit(new Patroller(700,550,400,1000,5*BASE_VELOCITY/3,80,hero));
	  island[0].addUnit(new Patroller(550,550,550,1000,5*BASE_VELOCITY/3,80,hero));
	  island[0].addUnit(new Burster(400,900,3*BASE_VELOCITY,50,hero));
	  island[0].addUnit(new Burster(600,900,3*BASE_VELOCITY,50,hero));
	  island[0].addUnit(new Burster(550,1100,3*BASE_VELOCITY,50,hero));
	  island[0].addUnit(new Shooter(400,1100,&island[0],hero));
	  island[0].addUnit(new Shooter(600,1100,&island[0],hero));
	  island[0].addUnit(new Tank(800, 1050,BASE_VELOCITY,200,hero));
	  island[0].addUnit(new Tank(800, 1150,BASE_VELOCITY,200,hero));
	  island[0].addUnit(new Shooter(1000,1050,&island[0],hero));
	  island[0].addUnit(new Shooter(1100,1150,&island[0],hero));
	  island[0].addArea(0,0,300,300,3);
	  island[0].addArea(300,200,500,1000, 5);
	  island[0].addArea(400,300,200,300, 1);
	  island[0].addArea(500,800,200,300, 1);
	  island[0].addArea(780,1000, 500, 200, 3);
	  island[0].addArea(1080,360,200,650, 2);
      
	  p2s=1;
	  currentstage=0;
	  break;
      
	case 7:   //Design South Island Level and go there
	  hero = new Hero(75,385,200,0,0,0,5000);
	  brad = new Brad(650,-800,750,-800,BASE_VELOCITY*3,130,&island[1],hero);
	  island[1].addUnit(hero);
	  island[1].addUnit(brad);
	  island[1].addUnit(new Burster(650,-700,3*BASE_VELOCITY,50,hero));
	  island[1].addUnit(new Burster(750, -700,3*BASE_VELOCITY,50,hero));
	  island[1].addUnit(new Patroller(100,100,400,400,5*BASE_VELOCITY/3,80,hero));
	  island[1].addUnit(new Tank(400, 50, BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Tank(450, 100,BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Shooter(1000, 25, &island[1],hero));
	  island[1].addUnit(new Shooter(1000, 100, &island[1],hero));
	  island[1].addUnit(new Burster(800, 50, 3*BASE_VELOCITY,50,hero));
	  island[1].addUnit(new Burster(800, 100, 3*BASE_VELOCITY,50,hero));
	  island[1].addUnit(new Tank(800, -200, BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Tank(800, -150, BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Tank(1000, -200, BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Tank(1000, -150, BASE_VELOCITY,200,hero));
	  island[1].addUnit(new Shooter(900, -175, &island[1],hero));
	  island[1].addUnit(new Shooter(800, -175, &island[1],hero));
	  island[1].addUnit(new Shooter(1000, -175, &island[1],hero));
	  island[1].addArea(0,0,500,500,5);
	  island[1].addArea(50,50,150,150,3);
	  island[1].addArea(500, 0, 600, 150,0);
	  island[1].addArea(1000, -100, 100, 100,1);
	  island[1].addArea(750,-250, 400, 150, 4);
	  island[1].addArea(750,-350,100,100,1);
	  island[1].addArea(600,-900,300,660,3);
				      
	  p2s=1;
	  currentstage=1;
	  break;

	case 8:   //Design East Level and go there
	  hero = new Hero(0,0,200,0,0,0,5000);

	  sean = new Sean(-650,-650,651,-652,653,654,-655,656,3*BASE_VELOCITY,180,&island[2],hero);
	  island[2].addUnit(hero);
	  island[2].addUnit(sean);
	  island[2].addUnit(new Shooter(-650,-650,&island[2],hero));
	  island[2].addUnit(new Shooter(650,650,&island[2],hero));
	  island[2].addUnit(new Shooter(650,-650,&island[2],hero));
	  island[2].addUnit(new Shooter(-650,650,&island[2],hero));
	  island[2].addUnit(new Shooter(-650,0,&island[2],hero));
	  island[2].addUnit(new Shooter(650,0,&island[2],hero));
	  island[2].addUnit(new Shooter(0,-650,&island[2],hero));
	  island[2].addUnit(new Shooter(0,650,&island[2],hero));
	  island[2].addUnit(new Tank(0,500,BASE_VELOCITY,200,hero));
	  island[2].addUnit(new Tank(0,-500,BASE_VELOCITY,200,hero));
	  island[2].addUnit(new Tank(500,0,BASE_VELOCITY,200,hero));
	  island[2].addUnit(new Tank(-500,0,BASE_VELOCITY,200,hero));
	  island[2].addUnit(new Patroller(-350,-100,-100,-350,5*BASE_VELOCITY/3,80,hero));
	  island[2].addUnit(new Patroller(350,100,100,350,5*BASE_VELOCITY/3,80,hero));
	  island[2].addUnit(new Patroller(-350,100,-100,350,5*BASE_VELOCITY/3,80,hero));
	  island[2].addUnit(new Patroller(350,-100,100,-350,5*BASE_VELOCITY/3,80,hero));
	  island[2].addUnit(new Burster(0,575,3*BASE_VELOCITY,50,hero));
	  island[2].addUnit(new Burster(0,-575,3*BASE_VELOCITY,50,hero));
	  island[2].addUnit(new Burster(575,0,3*BASE_VELOCITY,50,hero));
	  island[2].addUnit(new Burster(-575,0,3*BASE_VELOCITY,50,hero));
	  island[2].addArea(-400,-400,800,800,1);
	  island[2].addArea(-100, -100, 200,200,3);
	  island[2].addArea(-300,-300,200,200,3);
	  island[2].addArea(100,-300,200,200,3);
	  island[2].addArea(100,100,200,200,3);
	  island[2].addArea(-300,100,200,200,3);
	  island[2].addArea(-75,-550,150,150,2);
	  island[2].addArea(-75,400,150,150,2);
	  island[2].addArea(-550,-75,150,150,2);
	  island[2].addArea(400,-75,150,150,2);
	  island[2].addArea(-675,-675, 1385, 150,4);
	  island[2].addArea(-675,-545, 150, 1090,4);
	  island[2].addArea(-675, 550, 1375, 150,4);
	  island[2].addArea(550, -537, 150, 1090,4);
	  p2s=1;
	  currentstage=2;
	  break;

	case 9:   //Design North level and go there
	  hero= new Hero(200,-50,200,0,0,0,5000);
	  sneal = new Sneal(100,-3500,300,-3500,BASE_VELOCITY*3,250,&island[3],hero);
	  island[3].addUnit(hero);
	  island[3].addUnit(sneal);
	  island[3].addUnit(new Shooter(0,-3700,&island[3],hero));
	  island[3].addUnit(new Shooter(400,-3700,&island[3],hero));
	  island[3].addUnit(new Shooter(0,-3300,&island[3],hero));
	  island[3].addUnit(new Shooter(400,-3300,&island[3],hero));

	  island[3].addUnit(new Sean(50,-2750,351,-2752,353,-2454,55,-2456,3*BASE_VELOCITY,150, &island[3],hero));
	  island[3].addUnit(new Tank(200, -2600, BASE_VELOCITY,200,hero));
	  island[3].addUnit(new Tank(75, -2600, BASE_VELOCITY,200,hero));
	  island[3].addUnit(new Tank(325, -2600, BASE_VELOCITY,200,hero));
	
	  island[3].addUnit(new Brad(50,-1800,350,-1800,BASE_VELOCITY*3,130,&island[3],hero));	
	  island[3].addUnit(new Patroller(50,-1900,150,-1900,5*BASE_VELOCITY/3,80,hero));
	  island[3].addUnit(new Patroller(250,-1900,350,-1900,5*BASE_VELOCITY/3,80,hero));
	  island[3].addUnit(new Patroller(50,-1700,150,-1700,5*BASE_VELOCITY/3,80,hero));
	  island[3].addUnit(new Patroller(250,-1700,350,-1700,5*BASE_VELOCITY/3,80,hero));
	
	  island[3].addUnit(new Mike(50,-1150,350,-1150,3*BASE_VELOCITY,150, &island[3], hero));
	  island[3].addUnit(new Burster(50,-1000, 3*BASE_VELOCITY,50,hero));
	  island[3].addUnit(new Burster(350,-1000, 3*BASE_VELOCITY,50,hero));
	  island[3].addUnit(new Burster(150,-900, 3*BASE_VELOCITY,50,hero));
	  island[3].addUnit(new Burster(250,-900, 3*BASE_VELOCITY,50,hero));
	
	  island[3].addArea(0,-400,400,400,6); //Opening
	  island[3].addArea(150,-800,100,400,6);
	  island[3].addArea(0,-1200,400,400,6); //Boss 1
	  island[3].addArea(150,-1600,100,400,6);
	  island[3].addArea(0,-2000,400,400,6); //Boss 2
	  island[3].addArea(150,-2400,100,400,6);
	  island[3].addArea(0,-2800,400,400,6);  //Boss 3
	  island[3].addArea(150,-3200,100,400,6);
	  island[3].addArea(-100,-3800,600,600,6); //Sneal Boss
	  island[3].addArea(0,-3700,400,400,6);

	  p2s=1;
	  currentstage=3;
	  break;
	
	}
      if(p2s)    //If the current state is a stage state
	{
	  bossdead = false;    
	  while(bossdead==false && quit ==false){ //While the boss is still alive
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
		      case SDLK_ESCAPE:  
			quit = true;
			Stageless.init();
			break;
		      case SDLK_UP:   //The different bullet commands are here
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
		      case SDLK_f:    //Same full screen
			if(screen_state==0)
			  {
			    island[currentstage].init_fullscreen();
			    screen_state=1;
			  }
			else
			  {
			    island[currentstage].init();
			    screen_state=0;
			  }
			break;
		      case SDLK_1: //bullet color control
			if(already_west)
			  if(b==0) b=1;
			  else b=0;
			break;
		      case SDLK_2:
			if(already_south)
			  if(r==0) r=1;
			  else r=0;
			break;
		      case SDLK_3:
			if(already_east)
			  if(g==0) g=1;
			  else g=0;
			break;
		      }
		  }
	      }

	    help=0;  //Helps determine if boss is dead
	    island[currentstage].checkCollisions(hero);  //collision
	    switch(currentstage) //switch for each level to see if the boss for that level is dead
	      {
	      case 0:
		if(mike->getHealth()<=0)
		  {
		    next=10;
		    bossdead=true;
		    island[currentstage].clear_screen(); //Heads to new screen
		  }  
		else help=1; //Boss still alive
		break;
	      case 1:
		if(brad->getHealth()<=0)
		  {
		    next=11;
		    bossdead=true;
		    island[currentstage].clear_screen();
		  }
		else help=1;
		break;
	      case 2:
		if(sean->getHealth()<=0)
		  {
		    next=12;
		    bossdead=true;
		    island[currentstage].clear_screen();
		  }
		else help=1;
		break;
	      case 3:
		if(sneal->getHealth()<=0)
		  {
		    next=13;
		    bossdead=true;
		    island[currentstage].clear_screen();
		  }
		else help=1;
		break;
	      }
	    if(hero->isDead())
	      {
		island[currentstage].init();
		return 0;  //Quits program if you let hero die
	      }
	    if(!(hero->isDead()) && (help==1))  //if the hero isn't dead and the boss for this stage is alive
	      {
		//Progress the stage forward
		island[currentstage].perform(dt, hero);
		hero->processEvent(dt);
		island[currentstage].draw(r,g,b,already_south,already_east,already_west);
		duration = (clock() - start)/((double)CLOCKS_PER_SEC);
		  
		if (duration>dt)
		  {
		    duration=dt;
		  }
		usleep((dt-duration)*1000000);
	      }
	  } //End stage loop   
	  
	  sounds.change_music("music1"); //Changes back to menu music
	  sounds.play_music();
	  
	  if(currentstage==0) already_west = 1; //Keeps track of what levels you have beaten
	  if(currentstage==1) already_south = 1;
	  if(currentstage==2) already_east = 1;
	}
	
    }
  //End main while loop
  sounds.stop_music();
  sounds.clean_up_sound();
  //island[currentstage].clean_up();
}

