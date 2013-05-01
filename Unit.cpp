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

Unit::Unit(double X, double Y, double MAXV, double AX, double AY, int location, int h){
  x=X;
  y=Y;
  vx = 0;
  vy = 0;
  ax = AX;
  ay = AY;
  maxv=MAXV;
  char_left = NULL;
  char_right = NULL;
  load_files();
  set_clips(location);
  status = UNIT_RIGHT;
  moving = 0;
  frame = 0;
  setHealth(h);
  setMaxHealth(h);
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

void Unit::setmaxv(double max){
  maxv=max;
}

double Unit::getmaxv(){
  return maxv;
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
  char_left = load_image( "images/neal.png" );
  char_right = load_image( "images/nealflipped.png");

  //If there was an error in loading the characters
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

  // Character and direction
  if(status == UNIT_LEFT)
    {
      apply_surface( x+xo, y+yo, char_left, screen, &clip_char_left[frame]);
    }
  if(status == UNIT_RIGHT)
    {
      apply_surface( x+xo, y+yo, char_right, screen, &clip_char_right[frame]);
    }

  //Unit health
  // border = black outline
  SDL_Rect border, inside, missing;
  border.x = x+xo;
  border.y = y+yo-SPRLENGTH/6-1;
  border.w = SPRWIDTH;
  border.h = SPRLENGTH/6;
  SDL_FillRect( screen, &border, SDL_MapRGB( screen->format,0,0,0) );
  // missing = missing health in red
  // inside = green health bar
  inside.x = missing.x = x+xo+1;
  inside.y = missing.y = y+yo-SPRLENGTH/6;
  int currentHealth;
  int totalHealth=SPRWIDTH-2;
  currentHealth= totalHealth*getHealth()/getMaxHealth();
  inside.w = currentHealth;
  missing.w = totalHealth;
  inside.h = missing.h = SPRLENGTH/6-2;
  SDL_FillRect( screen, &missing, SDL_MapRGB( screen->format,255,0,0) );
  SDL_FillRect( screen, &inside, SDL_MapRGB( screen->format,0,128,255) );
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
  if( (vx + ax*dt) >= maxv)
    vx = maxv;
  else if( (vx + ax*dt) <= -maxv)
    vx = -maxv;
  else
    vx = vx + ax*dt;
  // vertical velocity
  if( (vy + ay*dt) >= maxv)
    vy = maxv;
  else if( (vy + ay*dt) <= -maxv)
    vy = -maxv;
  else
  vy = vy + ay*dt;

  if (sqrt(vx*vx+vy*vy) > maxv){
    angle = atan(vy/vx);
    if (vx < 0 && vy<0){
      vx = -maxv*cos(angle);
      vy = -maxv*sin(angle);
    }
    else if (vx<0 && vy>0){
      vx = -maxv*cos(angle);
      vy = -maxv*sin(angle);
    }
    else{
      vx = maxv*cos(angle);
      vy = maxv*sin(angle);
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

bool Unit::isCollided(Unit* unit)
{
  int BULLETSIZE = 9;
  if(unit->isBullet())
    {
      if(isBullet())
	{
	  if(x < unit->getx()-BULLETSIZE) //this is too far to the left
	    return false;
	  if(x > unit->getx()+BULLETSIZE) //this is too far to the right
	    return false; 
	  if(y < unit->gety()-BULLETSIZE) //this is too far up
	    return false;
	  if(y > unit->gety()+BULLETSIZE) //this is too far down
	    return false;
	  return true;
	}
      else
	{
	  if(x < unit->getx()-SPRWIDTH)
	    return false;
	  if(x > unit->getx()+BULLETSIZE)
	    return false;
	  if(y < unit->gety()-SPRLENGTH)
	    return false;
	  if(y > unit->gety()+BULLETSIZE)
	    return false;
	  return true;
	}
    }
  else
    {
      if(isBullet())
	{
	  if(x < unit->getx()-BULLETSIZE)
	    return false;
	  if(x > unit->getx()+SPRWIDTH)
	    return false;
	  if(y < unit->gety()-BULLETSIZE)
	    return false;
	  if(y > unit->gety()+SPRLENGTH)
	    return false;
	  return true;
	}
      else
	{
	  if(x < unit->getx()-SPRWIDTH)
	    return false;
	  if(x > unit->getx()+SPRWIDTH)
	    return false;
	  if(y < unit->gety()-SPRLENGTH)
	    return false;
	  if(y > unit->gety()+SPRLENGTH)
	    return false;
	  return true;
	}
    }
  return false;
}  

bool Unit::isBullet()
{
  return 0;
}

bool Unit::isFromHero()
{
  return 0;
}

int Unit::getHealth()
{
  return health;
}

void Unit::setHealth(int h)
{
  health = h;
}

int Unit::getMaxHealth()
{
  return maxHealth;
}

void Unit::setMaxHealth(int h)
{
  maxHealth = h;
}
