/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Hero header file */



#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define BULLETV 600


#include "Bullet.h"
#include "SDL/SDL.h"


Bullet::Bullet(Unit* shooter, int direction, int typez)
{
  switch(direction)
    {
    case UP:
      setx(shooter->getx());
      sety(shooter->gety());
      setvx(shooter->getvx());
      setvy(shooter->getvy() - BULLETV);
      setax(0);
      setay(0);
      break;
    case DOWN:
      setx(shooter->getx());
      sety(shooter->gety());
      setvx(shooter->getvx());
      setvy(shooter->getvy() + BULLETV);
      setax(0);
      setay(0);
      break;
    case LEFT:
      setx(shooter->getx());
      sety(shooter->gety());
      setvx(shooter->getvx() - BULLETV);
      setvy(shooter->getvy());
      setax(0);
      setay(0);
      break;
    case RIGHT:
      setx(shooter->getx());
      sety(shooter->gety());
      setvx(shooter->getvx() + BULLETV);
      setvy(shooter->getvy());
      setax(0);
      setay(0);
      break;
    }
  type = typez;

}

virtual void Bullet::draw(){
  
}
