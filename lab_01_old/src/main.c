#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "UI.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Инициализация GLUT с передачей параметров командной строки
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Инициализация режима отображения GLUT с указанием одинарного буфера и RGB-цветов
    glutInitWindowSize(1000, 1000); // Установка начального размера окна
    glutInitWindowPosition(100, 100); // Установка начальной позиции окна
    glutCreateWindow("3D Figure"); // Создание окна с указанным заголовком

    int rc = init(); // Вызов функции инициализации
    if (rc)
    {
        printf("Произошла ошибка памяти.\n");
        return rc;
    }
    glutDisplayFunc(display); // Установка функции отображения
    glutSpecialFunc(specialKeys); // Установка функции для обработки специальных клавиш
    glutKeyboardFunc(keyboard); // Установка функции для обработки клавиатурных событий
    glutMainLoop(); // Запуск главного цикла GLUT
    end(); // Вызов функции завершения

    return OK;
}
