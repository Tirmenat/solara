/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Enemy header file */

#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <iomanip>
#include "unit.h"

class Enemy: public Unit{
 public:
    virtual void draw();

 private:

};
