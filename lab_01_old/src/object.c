#include "object.h"
#include <stdlib.h>

// Функция инициализации объекта
object_t *init_object(void)
{
    object_t *obj = malloc(sizeof(object_t));   // Выделение памяти под объект
    if (obj)
    {
        obj->vertices = NULL;   // Установка массива вершин в NULL
        obj->edges = NULL;      // Установка массива рёбер в NULL
        obj->numVertices = 0;   // Установка количества вершин в 0
        obj->numEdges = 0;      // Установка количества рёбер в 0
        obj->position.angleX = 0.0f;    // Установка угла по оси X в 0
        obj->position.angleY = 0.0f;    // Установка угла по оси Y в 0
        obj->position.scale = 1.0f;     // Установка масштаба в 1
        obj->position.translateX = 0.0f;    // Установка смещения по оси X в 0
        obj->position.translateY = 0.0f;    // Установка смещения по оси Y в 0
    }
    return obj;     // Возврат указателя на объект
}

// Функция сброса объекта
void reset_object(object_t *obj)
{
    if (obj)
    {
        // Освобождение памяти массивов вершин и рёбер, если они были выделены
        if (obj->vertices)
            free(obj->vertices);
        if (obj->edges)
            free(obj->edges);
        obj->vertices = NULL;   // Установка массива вершин в NULL
        obj->edges = NULL;      // Установка массива рёбер в NULL
        obj->numVertices = 0;   // Установка количества вершин в 0
        obj->numEdges = 0;      // Установка количества рёбер в 0
        obj->position.angleX = 0.0f;    // Установка угла по оси X в 0
        obj->position.angleY = 0.0f;    // Установка угла по оси Y в 0
        obj->position.scale = 1.0f;     // Установка масштаба в 1
        obj->position.translateX = 0.0f;    // Установка смещения по оси X в 0
        obj->position.translateY = 0.0f;    // Установка смещения по оси Y в 0
    }
}

// Функция уничтожения объекта
void destroy_object(object_t *obj)
{
    if (obj)
    {
        // Освобождение памяти массивов вершин и рёбер, если они были выделены
        if (obj->vertices)
            free(obj->vertices);
        if (obj->edges)
            free(obj->edges);
        free(obj);  // Освобождение памяти объекта
    }
}
