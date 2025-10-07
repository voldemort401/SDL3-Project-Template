# SDL3 Project Template
A Template for SDL3 projects.  

## To compile and run
Edit the `CMakeLists.txt` file and replace *`PROJECTNAME`* with your projects name and *`EXECUTABLE`* with the executable's name.

Also if you decide to change file names of `main.cpp` and `processes.cpp` or add some new files should probably reflect that in this line
```cmake 
CMakeLists.txt

add_executable(EXECUTABLE_NAME src/main.cpp def/functions.cpp src/processes.cpp)

```
After that to compile just:

``` bash
$ cd build/
$ make
```


## Usage

In the `src/` folder there are 2 files 

``` bash
main.cpp
processes.cpp
```

The `main.cpp` is used to initalize this template and in the `processes.cpp` is where you write the code you want the program to execute.

``` cpp
process.cpp

void processes::outside_main_loop(SDL_Window* window, SDL_Renderer* renderer) 
void processes::process(double delta, SDL_Window* window, SDL_Renderer* renderer)
void processes::physics(double delta, SDL_Window* window, SDL_Renderer* renderer)
void processes::input(double delta, SDL_Event ev)
```

In the repo the `processes.cpp` just contains code to just render a circle with radius 4.
