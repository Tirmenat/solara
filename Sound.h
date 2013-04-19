/* FCII Final Project
Spring 2013
Michael Powers
Brad Stalcup
Sean Murphy
Neal Sheehan
Solara
Music implementation file */
#include <vector>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_music.h"

#define SOUND_H
#ifndef SOUND_H

class Sound{
public:
  Sound();
  void play_music(string std: song)
  void stop_music();
  void clean_up_sound();

private:
  bool init_sound();
  bool load_music();

};

#endif
