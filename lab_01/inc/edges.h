#ifndef __EDGES_H__
#define __EDGES_H__

#include "points.h"
#include "draw.h"
#include "err.h"

/// @brief  Структура для представления ребра
struct edge_t
{
    size_t p1;  /// точка 1
    size_t p2;  /// точка 2
};

/// @brief  Структура для представления массива ребер
struct edges_t
{
    edge_t *arr;  /// динамический массив
    size_t size;  /// размер массива
};

/**
 * @brief Инициализирует массив ребер
 *
 * @param edges [out] массив ребер
 */
void edges_init(edges_t &edges);

/**
 * @brief Считывает массив ребер из файла
 *
 * @param edges [out] массив ребер
 * @param edges [in/out] файл
 * 
 * @return rc - код ошибки
 */
err_t edges_input(edges_t &edges, FILE *f);

/**
 * @brief Проверяет корректность массива ребер
 *
 * @param edges [in] массив ребер
 * @param points_size [in] размер массива точек
 * 
 * @return rc - код ошибки (результат проверки)
 */
err_t edges_verify(edges_t &edges, size_t &points_size);

/**
 * @brief Рисует ребра
 *
 * @param scene [in/out] холст
 * @param edges [in] массив ребер
 * @param points [in] массив точек
 * 
 * @return rc - код ошибки
 */
err_t edges_draw(const scene_t &scene, const edges_t &edges, const points_t &points);

/**
 * @brief Освобождает массив ребер
 *
 * @param edges [in] массив ребер
 */
void edges_free(edges_t &edges);

#endif
