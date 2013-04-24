/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Music implementation file */
#include <vector>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "string.h"

#ifndef SOUND_H
#define SOUND_H

class Sound{
public:
  Sound();
  void play_music(std::string);
  void stop_music();
  void clean_up_sound();

private:
  Mix_Music *music1;
  Mix_Music *music2;
  Mix_Music *music3;
  Mix_Music *music4;
  Mix_Music *music5;
  bool init_sound();
  bool load_music();

};

#endif
