
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
	
    case 6:
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
      
      case 7:
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

      case 8:
	hero = new Hero(0,0,200,0,0,0,5000);

	sean = new Sean(50,50,50,100,100,100,100,50,4*BASE_VELOCITY,180,&island[2],hero);
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

      case 9:
	hero= new Hero(200,-50,200,0,0,0,5000);
	sneal = new Sneal(50,-100,150,-100,BASE_VELOCITY*3,250,&island[3],hero);
	island[3].addUnit(hero);
	island[3].addUnit(sneal);
	island[3].addArea(0,-400,400,400,3);
	

	p2s=1;
	currentstage=3;
	break;
	
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
		      case SDLK_ESCAPE:
			quit = true;
			Stageless.init();
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
		      case SDLK_e:
			next = 5;
			bossdead=true;
			island[currentstage].clear_screen();
			break;
		      case SDLK_f:
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
		
	      //mike.patrol();
	      //burster1.chase(hero.getx(),hero.gety());
	      //tank1.chase(hero.getx(),hero.gety());
	      //patrol1.chase(hero_test.getx(),hero_test.gety());
	      //patrol_test2.chase(hero_test.getx(),hero_test.gety());
	      //	    cout << "no here" << endl;
	      //	    cout << "here" << endl;
	      help=0;
	      island[currentstage].checkCollisions(hero);
	      switch(currentstage)
		{
		case 0:
		  if(mike->getHealth()<=0)
		    {
		      next=5;
		      bossdead=true;
		      island[currentstage].clear_screen();
		    }  
		  else help=1;
		  break;
		case 1:
		  if(brad->getHealth()<=0)
		    {
		      next=5;
		      bossdead=true;
		      island[currentstage].clear_screen();
		    }
		  else help=1;
		  break;
		case 2:
		  if(sean->getHealth()<=0)
		    {
		      next=5;
		      bossdead=true;
		      island[currentstage].clear_screen();
		    }
		  else help=1;
		  break;
		case 3:
		  if(sneal->getHealth()<=0)
		    {
		      next=5;
		      bossdead=true;
		      island[currentstage].clear_screen();
		    }
		  else help=1;
		  break;
		}
	      if(hero->isDead())
		{
		  island[currentstage].init();
		  return 0;
		}
	      if(!(hero->isDead()) && (help==1))
		{
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
	  
	  sounds.change_music("music1");
	  sounds.play_music();
	  
	  if(currentstage==0) already_west = 1;
	  if(currentstage==1) already_south = 1;
	  if(currentstage==2) already_east = 1;
	}
	
    }
  //End main while loop
  sounds.stop_music();
  sounds.clean_up_sound();
  //island[currentstage].clean_up();
}

