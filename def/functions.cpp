#include "private_functions.hpp"
#include "public_functions.hpp"
#include "processes.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_timer.h>
#include <iostream>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_init.h>
#include <cstddef>

processes process;
// private_functions
void cleanup(SDL_Window* window, SDL_Renderer* renderer){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit(); 

};


void main_loop(bool runnning, SDL_Window *window, SDL_Renderer *renderer){
  SDL_Event ev;
  Uint32 LAST; 
  Uint32 NOW = SDL_GetTicks();
  double delta;

  while (runnning == true){
    LAST = NOW;
    NOW = SDL_GetTicks();
    delta = (NOW - LAST) / double(1000); // divide by 1000 to convert to seconds
    
    while(SDL_PollEvent(&ev)){
      if (ev.type == SDL_EVENT_QUIT){
        runnning = false;  
      }
      process.input(delta,ev);
       
    }

    process.process(delta, window, renderer); 
    process.physics(delta, window, renderer);
    
    SDL_RenderPresent(renderer);
  }
};

// public function.hpp
void init(const char* title, int width, int height, int vsync ,SDL_WindowFlags flags){

  SDL_Init(SDL_INIT_VIDEO); 
  bool runnning = true; 
  SDL_Window *window = SDL_CreateWindow(title, width, height, flags);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  if (window == NULL){
    std::cout<<SDL_GetError();
    return;
  }

  if (renderer == NULL){
    std::cout<<SDL_GetError();
    return;
  }

  if (SDL_SetRenderVSync(renderer, vsync) == false){
    std::cout<<SDL_GetError();
    return;
  };
  

  process.outside_main_loop(window, renderer);
  main_loop(runnning, window, renderer);
  cleanup(window, renderer);

};



void setbg_color(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
  if (SDL_SetRenderDrawColor(renderer, r,  g,  b,  a) == false){
    std::cout<<SDL_GetError();
    return;
  }
  SDL_RenderClear(renderer);
};


void create_circle(Circle circle, SDL_Renderer *renderer,bool visible){
  if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) == false){
    std::cout<<SDL_GetError();
    return;
  };
  int x = 0; 
  int y = -circle.r; 
  while (x < -y){
    int ymid = y+1;
    if (x*x + ymid*ymid > circle.r*circle.r){
      y+=1;
    }
    if (visible == true){
       // for octants up and down 
       SDL_FPoint points[8];

       points[0].x =  x+circle.center.x;
       points[1].x =  -x+circle.center.x;
       points[2].x =  x+circle.center.x;
       points[3].x =  -x+circle.center.x;
       points[4].x =  y+circle.center.x;
       points[5].x =  -y+circle.center.x;
       points[6].x =  y+circle.center.x;
       points[7].x =  -y+circle.center.x;


       points[0].y =  y+circle.center.y;
       points[1].y =  y+circle.center.y; 
       points[2].y =  -y+circle.center.y;
       points[3].y =  -y+circle.center.y;
       points[4].y =  x+circle.center.y;
       points[5].y =  x+circle.center.y;
       points[6].y =  -x+circle.center.y;
       points[7].y =  -x+circle.center.y;

       if(SDL_RenderPoints(renderer, points, 8) == false){
         std::cout<<SDL_GetError();
         return;
       };
    }

    else
    {
      std::cout<<"x: "<<(x+circle.center.x) << "y: " << (y+circle.center.y)<<std::endl;  
    };
    x+=1;
  }

};
