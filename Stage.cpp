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
#include "SDL/SDL_image.h"
#include "Stage.h"
#include "Hero.h"
//DOES THIS WORK???

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

Stage::Stage(int x, int y)
{	
  units.push_back(new Hero(x,y,0,0,0,0));
  screen = NULL;
  background = NULL;
  init();
  load_files();
  set_clips();
  //Fill the screen white
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 255, 255, 255 ) );
  location = 5;
}

void Stage::perform()
{
  for(int i = 0; i < units.size(); i++)
    units[i]->increment();
}

SDL_Surface *Stage::load_image( std::string filename )
{
  //Lazyfoo.net

  //The image that's loaded
  SDL_Surface* loadedImage = NULL;

  //The optimized image that will be used
  SDL_Surface* optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load( filename.c_str() );

  //If the image loaded
  if( loadedImage != NULL )
    {
      //Create an optimized image
      optimizedImage = SDL_DisplayFormat( loadedImage );

      //Free the old image
      SDL_FreeSurface( loadedImage );

      //If the image was optimized just fine
      if( optimizedImage != NULL)
	{
	  //Map the color key
	  Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 136, 255);
	  //Set all pixels of color R 0, G 0 xFF, B 0xFF to be transparent
	  SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
	}
    }

  //Return the optimized image
  return optimizedImage;
}

void Stage::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
  //Lazyfoo.net

  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //Blit
  SDL_BlitSurface( source, clip , destination, &offset );
}

bool Stage::init()
{
  //Lazyfoo.net 

  //Initialize all SDL subsystems
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
      return false;
    }

  //Set up the screen
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

  //If there was an error in setting up the screen
  if( screen == NULL )
    {
      return false;
    }

  //Set the window caption
  SDL_WM_SetCaption( "Solara", NULL );

  //If everything initialized fine
  return true;
}

bool Stage::load_files()
{
  //Lazyfoo.net 

  //Load the surfaces
  background = load_image( "terrain.png");

  //If there was an error in loading the terrain
  if( background == NULL )
    {
      return false;
    }

  //If everything loaded fine
  return true;
}

void Stage::set_clips()
{
  //Clip range for terrain
  for(int i=0; i<60; ++i )
    {
    for(int j=0; j<22; ++j )
      {
	clip_background[ i ][ j ].x = 17*i+1;
	clip_background[ i ][ j ].y = 17*j+1;
	clip_background[ i ][ j ].w = 16;
	clip_background[ i ][ j ].h = 16;
      }
  }
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
	    apply_surface( x, y, background, screen, &clip_background[3+location*7][1]);
	  }
	  else if(y == areas[i].y + areas[i].h - 16){
	    //draw bottom left sprite
	    apply_surface( x, y, background, screen, &clip_background[1+location*7][4]);
	  }
	  else{
	    //draw left edge sprite
	    apply_surface( x, y, background, screen, &clip_background[3+location*7][2]);
	  }
	}
	else if(y == areas[i].y){//top row of sprites
	  if(x == areas[i].x + areas[i].w - 16){
	    //draw top right sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location*7][1]);
	  }
	    else{
	      //draw top edge sprite
	      apply_surface( x, y, background, screen, &clip_background[2+location*7][3]);
	    }
	}
	else if(x == areas[i].x+areas[i].w-16){//right most column of sprites
	  if(y == areas[i].y+areas[i].h-16){//bottom row of sprites
	    //draw bottom right corner sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location*7][6]);
	  }
	  else{
	    //draw right edge sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location*7][5]);
	  } 
	}
	else if(y == areas[i].y+areas[i].h-16){
	  //draw bottom edge sprite
	  apply_surface( x, y, background, screen, &clip_background[5+location*7][4]);
	}
	else{
	  //draw regular sprite
	  apply_surface( x, y, background, screen, &clip_background[2+location*7][2]);
	}
      }
    }
  }

  SDL_Flip(screen);

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

void Stage::clean_up()
{
  //Free the surfaces
  SDL_FreeSurface( background );

  //Quit SDL
  SDL_Quit();
}
