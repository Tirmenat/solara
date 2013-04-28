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
const int SPRWIDTH = 16;
const int SPRLENGTH = 24;

Stage::Stage(int x, int y)
{	
  //units.push_back(new Hero(x,y,0,0,0,0,0));
  screen = NULL;
  background = NULL;
  title = NULL;
  init();
  load_files();
  set_clips();
  addArea(SCREEN_WIDTH/10, SCREEN_HEIGHT/10, SCREEN_WIDTH*4/5, SCREEN_HEIGHT*4/5,0);
  xoffset = 100;
  yoffset = 100;
}

void Stage::perform(double dt, Unit* hero)
{
  xoffset = -hero->getx() + SCREEN_WIDTH/2;
  yoffset = -hero->gety() + SCREEN_HEIGHT/2;
  for(int i = 0; i < units.size(); i++)
    units[i]->increment(dt);
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

void Stage::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL, int xo = 0, int yo = 0 )
{
  //Lazyfoo.net

  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x + xo;
  offset.y = y + yo;

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
  title = load_image( "solaratitle.png" );

  if( title == NULL )
    {
      return false;
    }

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
  for(int i=0; i<60; ++i)
    {
    for(int j=0; j<22; ++j)
      {
	clip_background[i][j].x = 17*i+1;
	clip_background[i][j].y = 17*j+1;
	clip_background[i][j].w = 16;
	clip_background[i][j].h = 16;
      }
  }
}

void Stage::draw(){
  //Fill the screen black
  SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 32, 32, 32 ) );

  //drawing the terrain sprites
  for(int i = 0; i<areas.size(); i++){
    for(int x = areas[i].x; x<areas[i].x+areas[i].w; x+=16){
      for(int y = areas[i].y; y<areas[i].y+areas[i].h; y+=16){
	//draw correct sprite based on location
	if(x == areas[i].x){ //left most column of sprites
	  if(y == areas[i].y){ //top row of sprites
	    //draw top left corner sprite
	    apply_surface( x, y, background, screen, &clip_background[3+location[i]*7][1], xoffset, yoffset);
	  }
	  else if(y == areas[i].y + areas[i].h - 16){
	    //draw bottom left sprite
	    apply_surface( x, y, background, screen, &clip_background[1+location[i]*7][4], xoffset, yoffset);
	  }
	  else{
	    //draw left edge sprite
	    apply_surface( x, y, background, screen, &clip_background[3+location[i]*7][2], xoffset, yoffset);
	  }
	}
	else if(y == areas[i].y){//top row of sprites
	  if(x == areas[i].x + areas[i].w - 16){
	    //draw top right sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location[i]*7][1], xoffset,yoffset);
	  }
	    else{
	      //draw top edge sprite
	      apply_surface( x, y, background, screen, &clip_background[2+location[i]*7][3], xoffset, yoffset);
	    }
	}
	else if(x == areas[i].x+areas[i].w-16){//right most column of sprites
	  if(y == areas[i].y+areas[i].h-16){//bottom row of sprites
	    //draw bottom right corner sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location[i]*7][6], xoffset, yoffset);
	  }
	  else{
	    //draw right edge sprite
	    apply_surface( x, y, background, screen, &clip_background[4+location[i]*7][5], xoffset, yoffset);
	  } 
	}
	else if(y == areas[i].y+areas[i].h-16){
	  //draw bottom edge sprite
	  apply_surface( x, y, background, screen, &clip_background[5+location[i]*7][4], xoffset, yoffset);
	}
	else{
	  //draw regular sprite
	  apply_surface( x, y, background, screen, &clip_background[2+location[i]*7][2], xoffset, yoffset);
	}
      }
    }
  }

  for(int i = 0; i < units.size(); i++)
    if(isInBounds(units[i]->getx()/*minus size?*/, units[i]->gety()))
      units[i]->draw(screen,xoffset,yoffset);

  SDL_Flip(screen);
}

int Stage::addArea(int x, int y, int w, int h, int loc) //adds an area and checks to make sure it is added
{
  //sprite type
  location.push_back(loc);

  SDL_Rect add;
  add.x = x-x%16;
  add.y = y-y%16;
  add.w = w-w%16;
  add.h = h-h%16;
  areas.push_back(add);
  return 1;
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

void Stage::drawTitle()
{
  apply_surface(0,0,title,screen);
  if( SDL_Flip( screen ) == -1 )
    {
      return;
    }


}

void Stage::clear_screen()
{
  SDL_FillRect (screen, &screen->clip_rect, SDL_MapRGB (screen->format, 255, 255, 255));
  SDL_Flip(screen);
}

void Stage::clean_up()
{
  //Free the surfaces
  SDL_FreeSurface( background );

  //Quit SDL
  SDL_Quit();
}

void Stage::adjustUnits()
{
  bool topleft,topright,botleft,botright;

  for(int i = 0; i<units.size(); i++)
    {
      topleft = topright = botleft = botright = 1;
      if(isInBounds(units[i]->getx(),units[i]->gety()))
	topleft = 0;
      if(isInBounds(units[i]->getx()+SPRWIDTH,units[i]->gety()))
	topright = 0;
      if(isInBounds(units[i]->getx(),units[i]->gety()+SPRLENGTH))
	botleft = 0;
      if(isInBounds(units[i]->getx()+SPRWIDTH,units[i]->gety()+SPRLENGTH))
	botright = 0;
      //if topleft is in bounds
      //if top right is in bounds
      //if bottom left is in bounds
      //if bottom right is in bounds
      if(topleft || topright || botleft || botright)
	{
	  
	  while(!isInBounds(units[i]->getx()+SPRWIDTH,units[i]->gety()+SPRLENGTH) || !isInBounds(units[i]->getx(),units[i]->gety()+SPRLENGTH) || !isInBounds(units[i]->getx()+SPRWIDTH,units[i]->gety()) || !isInBounds(units[i]->getx(),units[i]->gety()))
	    {
	  units[i]->setx(units[i]->getx()+botleft*.5+topleft*.5-botright*.5-topright*.5);
	  units[i]->sety(units[i]->gety()-botleft*.5+topleft*.5-botright*.5+topright*.5);
	    }
	}
    }
}

int Stage::getoffsetx()
{
  return xoffset;
}

int Stage::getoffsety()
{
  return yoffset;
}
