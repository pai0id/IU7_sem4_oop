#ifndef __SDL_DRAW_H__
#define __SDL_DRAW_H__

#include <SDL2/SDL.h>

/// @brief Цвет
enum SDL_colors
{
    SDL_WHITE,
    SDL_BLACK,
    SDL_RED,
    SDL_GREEN,
    SDL_BLUE
};

/**
 * @brief Устанавливает цвет для рендерера.
 * 
 * Устанавливает цвет для рендерера renderer в соответствии с заданным именем цвета.
 * 
 * @param renderer Указатель на структуру SDL_Renderer, для которой устанавливается цвет.
 * @param color_name Имя цвета из перечисления SDL_colors.
 */
void set_color_canvas(SDL_Renderer *renderer, SDL_colors color_name);

/**
 * @brief Очищает рендерер.
 * 
 * Очищает рендерер renderer, заполняя его текущим цветом.
 * 
 * @param renderer Указатель на структуру SDL_Renderer, который требуется очистить.
 */
void clear_canvas(SDL_Renderer *renderer);

/**
 * @brief Рисует линию на рендерере.
 * 
 * Рисует линию на рендерере renderer, начиная с точки (x1, y1) и заканчивая точкой (x2, y2).
 * 
 * @param renderer Указатель на структуру SDL_Renderer, на котором будет отрисована линия.
 * @param x1 Координата x начальной точки линии.
 * @param y1 Координата y начальной точки линии.
 * @param x2 Координата x конечной точки линии.
 * @param y2 Координата y конечной точки линии.
 */
void draw_line_canvas(SDL_Renderer *renderer, int x1, int y1, int x2, int y2);

#endif
