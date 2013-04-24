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
#include "SDL/SDL_mixer.h"
#include "Sound.h"
#include <string>
#include "string.h"

bool Sound::init_sound(){

  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    return false;
  }

}

bool Sound::load_music(){
  music1 = NULL;
  music2 = NULL;
  music3 = NULL;
  music4 = NULL;
  music5 = NULL;

  music1 = Mix_LoadMUS( "songs/League_of_Legends_Theme_8_Bit.wav" );
  music2 = Mix_LoadMUS( "songs/Gerudo_Valley.wav" );
  music3 = Mix_LoadMUS( "songs/Martini_Rag.wav" );
  music4 = Mix_LoadMUS( "songs/Luigis_Mansion.wav" );
  music5 = Mix_LoadMUS( "songs/Lavender_Town_Dubstep.wav" );

  if (music1 == NULL || music2 == NULL || music3 == NULL || music4 == NULL || music5 == NULL) return false;

  return true;

}

Sound::Sound()
{
  init_sound();
  load_music();
}

void Sound::play_music(std::string song){
  if(song=="music1"){
    Mix_PlayMusic( music1, -1 );
  }
  if(song=="music2"){
    Mix_PlayMusic( music2, -1 );
  }
  if(song=="music3"){
    Mix_PlayMusic( music3, -1 );
  }
  if(song=="music4"){
    Mix_PlayMusic( music4, -1 );
  }
  if(song=="music5"){
    Mix_PlayMusic( music5, -1 );
  }

}

void Sound::stop_music(){

  Mix_HaltMusic();
  //clean_up_sound();
  //init_sound();
  //load_music();

}

void Sound::clean_up_sound(){

  Mix_FreeMusic( music1 );
  Mix_FreeMusic( music2 );
  Mix_FreeMusic( music3 );
  Mix_FreeMusic( music4 );
  Mix_FreeMusic( music5 );

  Mix_CloseAudio();

}
