/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero header file */

#include "Bullet.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <cmath>

Bullet::Bullet()
{
  red = 0;
  green = 0;
  blue = 0;
  bullet = NULL;
  load_files();
  set_clips();
}

Bullet::Bullet(Unit* shooter, double direction, int r, int g, int b, bool hero)
{
  //set location of bullet
  setx(shooter->getx()+SPRWIDTH/2-BULLETWIDTH/2);
  sety(shooter->gety()+SPRLENGTH/2-BULLETLENGTH/2);
  //set velocity of bullet
  setvx(shooter->getvx()/2 + BULLETV*cos(direction));
  setvy(shooter->getvy()/2 - BULLETV*sin(direction));
  //health of bullet
  //1=bullet on screen
  //0=bullet gone
  setHealth(1);
  setMaxHealth(1);
  /*  switch(direction)
    {
      

      
    case UP:
      setx(shooter->getx()+SPRWIDTH/2-BULLETWIDTH/2);
      sety(shooter->gety()-BULLETLENGTH);
      setvx(shooter->getvx());
      setvy(shooter->getvy() - BULLETV);
      break;
    case DOWN:
      setx(shooter->getx()+SPRWIDTH-BULLETWIDTH/2);
      sety(shooter->gety()+SPRLENGTH);
      setvx(shooter->getvx());
      setvy(shooter->getvy() + BULLETV);
      break;
    case LEFT:
      setx(shooter->getx()-BULLETWIDTH);
      sety(shooter->gety()+SPRLENGTH/2-BULLETLENGTH/2);
      setvx(shooter->getvx() - BULLETV);
      setvy(shooter->getvy());
      break;
    case RIGHT:
      setx(shooter->getx()+SPRWIDTH);
      sety(shooter->gety()+SPRLENGTH/2-BULLETLENGTH/2);
      setvx(shooter->getvx() + BULLETV);
      setvy(shooter->getvy());
      break;
      }*/
  
  fromHero = hero;
  setax(0);
  setay(0);
  setmaxv(BULLETV);
  red = r;
  green = g;
  blue = b;
  bullet = NULL;
  load_files();
  set_clips();
}

void Bullet::collide(Unit* u, double dt)
{

}

void Bullet::draw(SDL_Surface* screen, int xo, int yo)
{
  apply_surface( getx()+xo, gety()+yo, bullet, screen, &clip_bullet[getColor()]);
}

void Bullet::set_clips()
{
  //Clip range for bullet forms
  for(int i=0; i<BULLETNUM; ++i)
    {
      clip_bullet[i].x = 10*i;
      clip_bullet[i].y = 0;
      clip_bullet[i].w = BULLETWIDTH;
      clip_bullet[i].h = BULLETLENGTH;
    }
}

int Bullet::getColor()
{
  return(red*1 + green*2 + blue*4);
}

bool Bullet::isBullet()
{
  return(true);
}

bool Bullet::load_files()
{
  //Lazyfoo.net

  //Load the surfaces
  bullet = load_image( "images/bullet.png" );

  //If error in loading bullets
  if( bullet == NULL)
    {
      return false;
    }

  //If everything loaded fine
  return true;
}

SDL_Surface *Bullet::load_image( std::string filename )
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

void Bullet::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
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

bool Bullet::isFromHero()
{
  return fromHero;
}
