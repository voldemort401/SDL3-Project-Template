#include "public_functions.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

int main(){
  int width  = 600;
  int height = 400;
  init("title", width, height, -1);

  return 0;
}
