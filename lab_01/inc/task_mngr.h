#ifndef __TASK_MNGR_H__
#define __TASK_MNGR_H__

#include "object.h"
#include "draw.h"
#include "err.h"

/// @brief Виды запросов
enum action_t
{
    LOAD,   /// Загрузка объекта из файла
    MOVE,   /// Перемещение объекта
    SCALE,  /// Масштабирование объекта
    ROTATE, /// Поворот объекта
    DRAW,   /// Отрисовка объекта
    DESTROY /// Очистка памяти
};

/// @brief  Структура для представления запроса
struct task_t
{
    action_t action;  /// Тип запроса
    point_t center;   /// Точка поворота/масштабирования
    union             /// Данные для запроса
    {
        const char *filename;
        move_t move_coefs;
        scale_t scale_coefs;
        rotate_t rotate_coefs;
        scene_t scene;
    };
};

/**
 * @brief Обрабатывает задачу.
 * 
 * Выполняет указанное действие в соответствии с задачей task.
 * 
 * @param task Ссылка на структуру task_t, содержащую информацию о задаче.
 * @return Код ошибки (0 в случае успеха).
 */
err_t process_task(task_t &task);

#endif
