#ifndef __DRAW_H__
#define __DRAW_H__

#include "SDL_draw.h"
#include "points.h"
#include "err.h"

/// @brief  Структура для представления холста
struct scene_t
{
    SDL_Renderer *renderer;  /// холст
    SDL_colors bg_color;     /// цвет фона
    SDL_colors draw_color;   /// цвет отрисовки
    double width;            /// ширина холста
    double height;           /// Высота холста
};

/**
 * @brief Рисует линию между точками.
 *
 * @param scene [in/out] холст
 * @param p1 [in] точка 1
 * @param p2 [in] точка 2
 */
void draw_line(const scene_t &scene, const point_t &p1, const point_t &p2);

/**
 * @brief Очищает холст.
 *
 * @param scene [in/out] холст
 */
void clear(const scene_t &scene);

#endif
