#ifndef PUBLIC_FUNCTIONS 
#define PUBLIC_FUNCTIONS 
#pragma once
#include <SDL3/SDL_video.h>

/* i chose 15 as the acceleartion due to gravity because it looks smooth any less
 * lets say 9.8 or something starts to stutter and isnt very smooth i find that 15 is the 
 * smallest you can go before it starts to stutter*/

const int acc_g = 15;

#include <SDL3/SDL_render.h>
#include <SDL3/SDL.h>

typedef struct{
  float x;
  float y;
} Vector2;

typedef struct{
  Vector2 center;
  float r;
} Circle;

void init(const char* title, int width, int height, int vsync = -1,SDL_WindowFlags flag = 0);
void setbg_color(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void create_circle(Circle circle, SDL_Renderer* renderer, bool visible = true);

#endif
