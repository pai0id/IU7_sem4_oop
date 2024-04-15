#ifndef __UI_H__
#define __UI_H__

#include <SDL2/SDL.h>

#include "err.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MOVEMENT_SPEED 5

err_t init(SDL_Window **window, SDL_Renderer **renderer);

void run(SDL_Renderer *renderer);

void cleanup(SDL_Window *window, SDL_Renderer *renderer);

#endif
