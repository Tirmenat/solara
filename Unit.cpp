/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Unit Implementation file */


#include <iostream>
#include <iomanip>
#include "Unit.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <cmath>

#define SPRLENGTH 24
#define SPRWIDTH 16
#define UNIT_LEFT 0
#define UNIT_RIGHT 1
#define MAX_VX 150
#define MAX_VY 150
#define MAX_V 150

Unit::Unit(){
  x=0;
  y=0;
  vx=0;
  vy=0;
  ax=0;
  ay=0;
  char_left = NULL;
  char_right = NULL;
  load_files();
  set_clips(0);
  status = UNIT_RIGHT;
  moving = 0;
  frame = 0;
}

Unit::Unit(double X, double Y, double VX, double VY, double AX, double AY, int location){
  x=X;
  y=Y;
  vx = VX;
  vy = VY;
  ax = AX;
  ay = AY;
  char_left = NULL;
  char_right = NULL;
  load_files();
  set_clips(location);
  status = UNIT_RIGHT;
  moving = 0;
  frame = 0;
}

// Set Functions
void Unit::setx(double newx){
  x=newx;
}

void Unit::sety(double newy){
  y=newy;
}

void Unit::setax(double newax){
  ax=newax;
}

void Unit::setay(double neway){
  ay=neway;
}

void Unit::setvx(double newvx){
  vx=newvx;
}

void Unit::setvy(double newvy){
  vy=newvy;
}

// Get Functions
double Unit::getx(){
  return(x);
}

double Unit::gety(){
  return(y);
}

double Unit::getax(){
  return(ax);
}

double Unit::getay(){
  return(ay);
}

double Unit::getvx(){
  return(vx);
}

double Unit::getvy(){
  return(vy);
}

/*SDL_Rect Unit::getrect(){
  return clip;
  }*/

SDL_Surface *Unit::load_image( std::string filename )
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

void Unit::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
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

bool Unit::load_files()
{
  //Lazyfoo.net 

  //Load the surfaces
  char_left = load_image( "neal.png" );
  char_right = load_image( "nealflipped.png");

  //If there was an error in loading the terrain
  if( (char_left == NULL) || (char_right == NULL) )
    {
      return false;
    }

  //If everything loaded fine
  return true;
}

void Unit::set_clips(int location){
  //Clip range for characters
  for(int i=0; i<11; ++i)
    {
      clip_char_left[i].x = 30*i;
      clip_char_left[i].y = location*30;
      clip_char_left[i].w = SPRWIDTH;
      clip_char_left[i].h = SPRLENGTH;
    }

  //Clip range for flipped characters
  for(int i=0; i<11; ++i)
    {
      clip_char_right[i].x = 684 - 30*i; //684
      clip_char_right[i].y = location*30;
      clip_char_right[i].w = SPRWIDTH;
      clip_char_right[i].h = SPRLENGTH;
    }

}

void Unit::draw(SDL_Surface* screen, int xo, int yo){
  /*if(vx > 0)
	{
		status = UNIT_RIGHT;  //Unit moves left
		frame++; //animation continues
	}
	if(vx < 0)
	{
		status = UNIT_LEFT; //Unit moves right
		frame++; //animation continues
	}
	else
	{
		frame = 0; //Animation stops at neutral position
	}
	if(frame >= 3)
	{
		frame = 0;
		}*/
	if(status == UNIT_LEFT){
	  apply_surface( x + xo, y + yo, char_left, screen, &clip_char_left[frame]);
	}
	if(status == UNIT_RIGHT){
	  apply_surface( x + xo, y + yo, char_right, screen, &clip_char_right[frame]);
	}
}

bool Unit::isEqualTo(Unit* u)
{
  	if(u->getx() != x)
		return false;
	if(u->getx() != y)
		return false;
	if(u->getvx() != vx)
		return false;
	if(u->getvy() != vy)
		return false;
	if(u->getax() != ax)
		return false;
	if(u->getay() != ay)
		return false;
	return true;
}

/*
bool Unit::operator==(Unit* u){ //returns 1 if u and *this are the same
	//right now this isn't foolproof, may have to work on it l
	if(u->getx() != x)
		return false;
	if(u->getx() != y)
		return false;
	if(u->getdx() != dx)
		return false;
	if(u.getdy() != dy)
		return false;
	if(u.getax() != ax)
		return false;
	if(u.getay() != ay)
		return false;
	return true;
	}*/

void Unit::increment(double dt){
  frameShift();
  double angle;
  x=x + vx*dt;
  y=y + vy*dt;
  //  if(moving)
  // horizontal velocity
  if( (vx + ax*dt) >= MAX_VX)
    vx = MAX_VX;
  else if( (vx + ax*dt) <= -MAX_VX)
    vx = -MAX_VX;
  else
    vx = vx + ax*dt;
  // vertical velocity
  if( (vy + ay*dt) >= MAX_VY)
    vy = MAX_VY;
  else if( (vy + ay*dt) <= -MAX_VY)
    vy = -MAX_VY;
  else
  vy = vy + ay*dt;

  if (sqrt(vx*vx+vy*vy) > MAX_V){
    angle = atan(vy/vx);
    if (vx < 0 && vy<0){
      vx = -MAX_V*cos(angle);
      vy = -MAX_V*sin(angle);
    }
    else if (vx<0 && vy>0){
      vx = -MAX_V*cos(angle);
      vy = -MAX_V*sin(angle);
    }
    else{
      vx = MAX_V*cos(angle);
      vy = MAX_V*sin(angle);
    }
  }

}
void Unit::frameShift()
{
   if(ax>0)
    {
      status = UNIT_RIGHT;
    }
   else if(ax<0)
     {
       status = UNIT_LEFT;
     }
   else if(vx>0)
     {
       status = UNIT_RIGHT;    
     }
   else if(vx<0)
     {
       status = UNIT_LEFT;
     }
   
  if(vx!=0 || vy != 0)
    {
      moving++;
    }
  else
    {
      moving = 0;
      frame = 0;
    }
  if(moving>9)
    {
      
      moving = 0;
      frame = (frame==1) ? 0 : 1;
    }
}

bool Unit::isBullet()
{
  return 0;
}
