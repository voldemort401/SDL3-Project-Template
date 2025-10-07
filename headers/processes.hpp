#ifndef PROCESSES
#pragma once 
#define PROCESSES 

#include <SDL3/SDL_render.h>
#include <SDL3/SDL.h>


struct processes{
  void input(double delta,SDL_Event ev);
  void physics(double delta, SDL_Window* window, SDL_Renderer* renderer);
  void process(double delta, SDL_Window* window, SDL_Renderer* renderer);
  void outside_main_loop(SDL_Window* window,SDL_Renderer* renderer);
};

#endif
