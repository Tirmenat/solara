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

bool Sound::load_music(std::string song){
  music = NULL;

  if(song=="music1"){
    music = Mix_LoadMUS( "songs/League_of_Legends_Theme_8_Bit.wav" );
  }
  if(song=="music2"){
    music = Mix_LoadMUS( "songs/Gerudo_Valley.wav" );
  }
  if(song=="music3"){
    music = Mix_LoadMUS( "songs/Martini_Rag.wav" );
  }
  if(song=="music4"){
    music = Mix_LoadMUS( "songs/Luigis_Mansion.wav" );
  }
  if(song=="music5"){
    music = Mix_LoadMUS( "songs/Lavender_Town.wav" );
  }
  if (music == NULL) return false;

  return true;

}

void Sound::load_effects(){

  croak = Mix_LoadWAV( "sfx/FrogCroak.wav" );
  lasergun = Mix_LoadWAV( "sfx/LaserGun.wav" );
  gun = Mix_LoadWAV( "sfx/Gun.wav" );
  woah = Mix_LoadWAV( "sfx/Woah.wav" );
  playerdeath = Mix_LoadWAV( "sfx/PlayerDeath.wav" );
  enemydeath = Mix_LoadWAV( "sfx/EnemyDeath.wav" );
  ouch = Mix_LoadWAV( "sfx/Ouch.wav" );
  boop = Mix_LoadWAV( "sfx/Boop.wav" );

}

Sound::Sound()
{
  init_sound();
  load_effects();
}

void Sound::play_effect(std::string sound){
  if(sound=="croak"){
    Mix_PlayChannel(-1, croak, 0);
  }
  if(sound=="lasergun"){
    Mix_PlayChannel(-1, lasergun, 0);
  }
  if(sound=="gun"){
    Mix_PlayChannel(-1, gun, 0);
  }
  if(sound=="woah"){
    Mix_PlayChannel(-1, woah, 0);
  }
  if(sound=="playerdeath"){
    Mix_PlayChannel(-1, playerdeath, 0);
  }
  if(sound=="enemydeath"){
    Mix_PlayChannel(-1, enemydeath, 0);
  }
  if(sound=="ouch"){
    Mix_PlayChannel(-1, ouch, 0);
  }
  if(sound=="boop"){
    Mix_PlayChannel(-1, boop, 0);
  }

}

void Sound::play_music(){
  Mix_PlayMusic( music, -1 );
}

void Sound::change_music(std::string song){
  Mix_HaltMusic();
  Mix_FreeMusic( music );
  load_music(song);
}

void Sound::stop_music(){

  Mix_HaltMusic();

}

void Sound::clean_up_sound(){

  Mix_FreeChunk( croak );
  Mix_FreeChunk( lasergun );
  Mix_FreeChunk( gun );
  Mix_FreeChunk( woah );
  Mix_FreeChunk( playerdeath );
  Mix_FreeChunk( enemydeath );
  Mix_FreeChunk( ouch );
  Mix_FreeChunk( boop );
  Mix_FreeMusic( music );

  Mix_CloseAudio();

}
