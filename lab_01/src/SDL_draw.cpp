#include "SDL_draw.h"

struct SDL_color_t
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

static void init_SDL_color_t(SDL_color_t &color, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
}

static SDL_color_t get_color(SDL_colors color_name)
{
    SDL_color_t color;
    switch (color_name)
    {
    case SDL_WHITE:
        init_SDL_color_t(color, 0, 0, 0, 0);
        break;
    case SDL_BLACK:
        init_SDL_color_t(color, 0, 0, 0, 255);
        break;
    case SDL_RED:
        init_SDL_color_t(color, 255, 0, 0, 255);
        break;
    case SDL_GREEN:
        init_SDL_color_t(color, 0, 255, 0, 255);
        break;
    case SDL_BLUE:
        init_SDL_color_t(color, 0, 0, 255, 255);
        break;
    default:
        init_SDL_color_t(color, 0, 0, 0, 0);
        break;
    }
    return color;
}

void set_color_canvas(SDL_Renderer *renderer, SDL_colors color_name)
{
    SDL_color_t color = get_color(color_name);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void clear_canvas(SDL_Renderer *renderer)
{
    SDL_RenderClear(renderer);
}

void draw_line_canvas(SDL_Renderer *renderer, int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
