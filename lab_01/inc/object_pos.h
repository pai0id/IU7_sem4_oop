#ifndef __OBJ_POS_H__
#define __OBJ_POS_H__

/// @brief  Структура для представления коэфициентов перемещения
struct move_t
{
    double dx;
    double dy;
    double dz;
};

/// @brief  Структура для представления коэфициентов масштабирования
struct scale_t
{
    double kx;
    double ky;
    double kz;
};

/// @brief  Структура для представления углов поворота
struct rotate_t
{
    double ax;
    double ay;
    double az;
};

#endif
