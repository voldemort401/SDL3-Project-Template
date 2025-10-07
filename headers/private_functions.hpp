#ifndef PRIVATE_FUNCTIONS 
#define PRIVATE_FUNCTIONS 
#pragma once

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
void cleanup(SDL_Window* window, SDL_Renderer* renderer);
void main_loop(bool running, SDL_Window* window, SDL_Renderer* renderer);

#endif 
