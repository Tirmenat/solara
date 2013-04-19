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
#include "Sound.h"

Sound::Sound()
{
  init_sound();
  load_music();
}

void Sound::play_music(sting song){

  Mix_PlayMusic( song, -1 )

}

void Sound::stop_music{

  Mix_HaltMusic();

}

bool Sound::init_sound(){

  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    return false;
  }

}

bool Sound::load_music(){

  music1 = Mix_LoadWAV( "League_of_Legends_Theme_8_Bit.wav" );

  if (music1 == NULL) return false;

  return true;

}

void Sound::clean_up_sound(){

Mix_FreeMusic( music1 );

Mix_CloseAudio();

}
