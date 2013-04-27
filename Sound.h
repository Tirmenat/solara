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
  void play_music();
  void change_music(std::string);
  void stop_music();
  void clean_up_sound();
  bool load_music(std::string);

private:
  Mix_Music *music;
  bool init_sound();

};

#endif
