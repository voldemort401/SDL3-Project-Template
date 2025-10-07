#include "processes.hpp"
#include "public_functions.hpp"

Circle circle;
void processes::outside_main_loop(SDL_Window* window, SDL_Renderer* renderer){
  circle = {300,300,4};
}
void processes::process(double delta, SDL_Window* window, SDL_Renderer* renderer){
  setbg_color(renderer, 200, 255, 200, 255);
  create_circle(circle, renderer);
};
void processes::physics(double delta, SDL_Window* window, SDL_Renderer* renderer){
  return;
};
void processes::input(double delta, SDL_Event ev){
  return;
};
