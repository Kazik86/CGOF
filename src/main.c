#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <unistd.h>
#include "app.h"
#include "debug.h"
#include "common.h"

#define CAPTION "Life"
SDL_Surface* screen = NULL; 
const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 100;
const int SCREEN_BPP = 32;

bool_e init(void)
{
  /* */
  if(SDL_Init(SDL_INIT_EVERYTHING) == -1) return FALSE;

  /* */
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

  /* */
  if(screen == NULL) return FALSE;

  /* */
  if( TTF_Init() == -1 )return FALSE;

  /* */
  SDL_WM_SetCaption( CAPTION, NULL );

  SDL_FillRect ( screen, NULL, 0x00FF0000 );

  return TRUE;
}


/*
 *void put_pixel32 ( SDL_Surface *surface, int x, int y, Uint32 pixel )
 *{
 *  //Convert the pixels to 32 bit
 *  Uint32 *pixels = (Uint32 *)surface->pixels;
 *  //Set the pixel
 *  pixels[ ( y * surface->w ) + x ] = pixel;
 *}
 */

int main ( int argc,char** argv)
{
  init ( );
  run_app ( screen );
}
