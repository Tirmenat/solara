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


Bullet::Bullet(Unit* shooter, int direction, int r, int g, int b)
{
  switch(direction)
    {
    case UP:
      setx(shooter->getx()+SPRWIDTH/2-BULLETWIDTH/2);
      sety(shooter->gety()-BULLETLENGTH);
      setvx(shooter->getvx());
      setvy(shooter->getvy() - BULLETV);
      setax(0);
      setay(0);
      break;
    case DOWN:
      setx(shooter->getx()+SPRWIDTH-BULLETWIDTH/2);
      sety(shooter->gety()+SPRLENGTH);
      setvx(shooter->getvx());
      setvy(shooter->getvy() + BULLETV);
      setax(0);
      setay(0);
      break;
    case LEFT:
      setx(shooter->getx()-BULLETWIDTH);
      sety(shooter->gety()+SPRLENGTH/2-BULLETLENGTH/2);
      setvx(shooter->getvx() - BULLETV);
      setvy(shooter->getvy());
      setax(0);
      setay(0);
      break;
    case RIGHT:
      setx(shooter->getx()+SPRWIDTH);
      sety(shooter->gety()+SPRLENGTH/2-BULLETLENGTH/2);
      setvx(shooter->getvx() + BULLETV);
      setvy(shooter->getvy());
      setax(0);
      setay(0);
      break;
    }
  red = r;
  green = g;
  blue = b;
}

void Bullet::draw(SDL_Surface* screen, int xo, int yo){
  apply_surface( x+xo, y+yo, bullet, screen, &clip_bullet[getColor()]);
}

void Bullet::set_clips(){
  //Clip range for bullet forms
  for(int i=0; i<BULLETNUM; ++i)
    {
      clip_bullet[i].x = 10*i;
      clip_bullet[i].y = 0;
      clip_bullet[i].w = SPRWIDTH;
      clip_bullet[i].h = SPRLENGTH;
    }
}

int Bullet::getColor(){
  return(red*1 + green*2 + blue*4);
}

bool Bullet::isBullet(){
  return(true);
}
