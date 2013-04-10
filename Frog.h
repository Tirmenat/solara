/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Frog header file */

#ifndef FROG_H
#define FROG_H

#include <iostream>
#include <iomanip>
#include "Enemy.h"

class Frog: public Enemy{
  public:
    Frog(int, int);
    virtual void collide(Unit* u);
    virtual void draw();

  private:
    int health = 5;

}
