//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <iostream>

//Screen attributes
const int SCREEN_WIDTH = 1152;
const int SCREEN_HEIGHT = 648;
const int SCREEN_BPP = 32;
const int SPRT_SIZE = 4;
const int BKGD_SIZE = 100;


//The surfaces
SDL_Surface *image = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *sprite = NULL;
SDL_Surface *background = NULL;

//The event structure that will be used
SDL_Event event;

SDL_Rect clip_sprite[SPRT_SIZE];
SDL_Rect clip_background[BKGD_SIZE];

SDL_Surface *
load_image (std::string filename)
{
  //The image that's loaded
  SDL_Surface *loadedImage = NULL;

  //The optimized image that will be used
  SDL_Surface *optimizedImage = NULL;

  //Load the image
  loadedImage = IMG_Load (filename.c_str ());

  //If the image loaded
  if (loadedImage != NULL)
    {
      //Create an optimized image
      optimizedImage = SDL_DisplayFormat (loadedImage);

      //Free the old image
      SDL_FreeSurface (loadedImage);
    }

  if (optimizedImage != NULL)
    {
      //Map the color key
      Uint32 colorkey = SDL_MapRGB (optimizedImage->format, 0, 136, 255);
      //Set all pixels of color R 0, G 0 xFF, B 0xFF to be transparent
      SDL_SetColorKey (optimizedImage, SDL_SRCCOLORKEY, colorkey);
    }


  //Return the optimized image
  return optimizedImage;
}

void
apply_surface (int x, int y, SDL_Surface * source, SDL_Surface * destination,
	       SDL_Rect * clip = NULL)
{
  //Temporary rectangle to hold the offsets
  SDL_Rect offset;

  //Get the offsets
  offset.x = x;
  offset.y = y;

  //Blit the surface
  SDL_BlitSurface (source, clip, destination, &offset);
}

bool
init ()
{
  //Initialize all SDL subsystems
  if (SDL_Init (SDL_INIT_EVERYTHING) == -1)
    {
      return false;
    }

  //Set up the screen
  screen =
    SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  //If there was an error in setting up the screen
  if (screen == NULL)
    {
      return false;
    }


  //Set the window caption
  SDL_WM_SetCaption ("Solara Sprite Test", NULL);

  //If everything initialized fine
  return true;
}

bool
load_files ()
{
  //Load the image
  image = load_image ("Solara_TitleV1.png");

  sprite = load_image ("neal.png");

  background = load_image ("terrain.png");

  //If there was an error in loading the image
  if (image == NULL)
    {
      return false;
    }

  if (sprite == NULL)
    {
      return false;
    }

  //If everything loaded fine
  return true;
}

void
clean_up ()
{
  //Free the image
  SDL_FreeSurface (image);
  SDL_FreeSurface (background);
  SDL_FreeSurface (sprite);

  //Quit SDL
  SDL_Quit ();
}

void
set_clips ()
{
  //Clip range for neal
  clip_sprite[0].x = 0;
  clip_sprite[0].y = 0;
  clip_sprite[0].w = 16;
  clip_sprite[0].h = 24;

  //Clip range for terrain
  int loc = 0;
  for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
	{
	  clip_background[loc].x = 17 * i + 1;
	  clip_background[loc].y = 17 * j + 1;
	  clip_background[loc].w = 16;
	  clip_background[loc].h = 16;
	  ++loc;
	}
    }
}

int
main (int argc, char *args[])
{
  //Make sure the program waits for a quit
  bool quit = false;
  bool next = false;

  //Initialize
  if (init () == false)
    {
      return 1;
    }

  //Load the files
  if (load_files () == false)
    {
      return 1;
    }

  //set the clips
  set_clips ();

  //Apply the surface to the screen
  apply_surface (0, 0, image, screen);

  //Update the screen
  if (SDL_Flip (screen) == -1)
    {
      return 1;
    }

  //While the user hasn't quit
  while (quit == false)
    {

      //While there's an event to handle
      while (SDL_PollEvent (&event))
	{


	  if (event.type == SDL_KEYDOWN)
	    {
	      //Set the proper message surface
	      switch (event.key.keysym.sym)
		{
		case SDLK_q:
		  quit = true;
		  break;
		case SDLK_k:
		  quit = true;
		  next = true;
		  break;
		}
	    }

	  //If the user has Xed out the window
	  else if (event.type == SDL_QUIT)
	    {
	      //Quit the program
	      quit = true;
	    }
	}
    }

  int bkgd_loc;
  int neal_loc[2] = {2,2};
  quit = false;
  if (next == true)
    {
      SDL_FillRect (screen, &screen->clip_rect,
		    SDL_MapRGB (screen->format, 0xFF, 0xFF, 0xFF));
      bkgd_loc = 0;
      for (int i = 0; i < 8; ++i)
	{
	  for (int j = 0; j < 8; ++j)
	    {
	      apply_surface (16 * i, 16 * j, background, screen,
			     &clip_background[bkgd_loc]);
	      ++bkgd_loc;
	    }
	}
      apply_surface (neal_loc[0]*16, (neal_loc[1]-1)*16, sprite, screen, &clip_sprite[0]);
      if (SDL_Flip (screen) == -1)
	{
	  return 1;
	}
    }


  while (quit == false && next == true)
    {
      while (SDL_PollEvent (&event))
	{

	  if (event.type == SDL_KEYDOWN)
	    {
	      //Set the proper message surface                                       
	      switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		  quit = true;
		  break;


		case SDLK_w:
		  bkgd_loc = 0;
		  for (int i = 0; i < 8; ++i)
		    {
		      for (int j = 0; j < 8; ++j)
			{
			  apply_surface (16 * i, 16 * j, background, screen,
					 &clip_background[bkgd_loc]);
			  ++bkgd_loc;
			}
		    }
		  //Update location
		  neal_loc[1]--;
		  //Update sprite surface
		  apply_surface (neal_loc[0] * 16, (neal_loc[1] - 1) * 16,
				 sprite, screen, &clip_sprite[0]);
		  break;

		case SDLK_s:
		  //Down Arrow Key
		  //Update the background
		  bkgd_loc = 0;
		  for (int i = 0; i < 8; ++i)
		    {
		      for (int j = 0; j < 8; ++j)
			{
			  apply_surface (16 * i, 16 * j, background, screen,
					 &clip_background[bkgd_loc]);
			  ++bkgd_loc;
			}
		    }
		  //Update location
		  neal_loc[1]++;
		  //Update sprite surface
		  apply_surface (neal_loc[0] * 16, (neal_loc[1] - 1) * 16,
				 sprite, screen, &clip_sprite[0]);
		  break;

		case SDLK_a:
		  //Left Arrow Key
		  //Update the background
		  bkgd_loc = 0;
		  for (int i = 0; i < 8; ++i)
		    {
		      for (int j = 0; j < 8; ++j)
			{
			  apply_surface (16 * i, 16 * j, background, screen,
					 &clip_background[bkgd_loc]);
			  ++bkgd_loc;
			}
		    }
		  //Update location
		  neal_loc[0]--;
		  //Update sprite surface
		  apply_surface (neal_loc[0] * 16, (neal_loc[1] - 1) * 16,
				 sprite, screen, &clip_sprite[0]);
		  break;

		case SDLK_d:
		   //Right Arrow Key
		  //Update the background
		  bkgd_loc = 0;
		  for (int i = 0; i < 8; ++i)
		    {
		      for (int j = 0; j < 8; ++j)
			{
			  apply_surface (16 * i, 16 * j, background, screen,
					 &clip_background[bkgd_loc]);
			  ++bkgd_loc;
			}
		    }
		  //Update location
		  neal_loc[0]++;
		  //Update sprite surface
		  apply_surface (neal_loc[0] * 16, (neal_loc[1] - 1) * 16,
				 sprite, screen, &clip_sprite[0]);
		  break;
		}
	    }

	  else if (event.type == SDL_QUIT)
	    //Quit the program                                                                                       
	    quit = true;
	}

     
      if( SDL_Flip( screen ) == -1 )
	{
	  return 1;
	}
    }





  //Free the surface and quit SDL
  clean_up ();

  return 0;
}
