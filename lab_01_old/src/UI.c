#include "UI.h"
#include "str_read.h"
#include "file_sys.h"
#include <GL/glut.h>
#include <stdio.h>

static object_t *obj;   // Переменная для объекта

// Функция инициализации
int init()
{
    obj = init_object();    // Инициализация объекта
    if (!obj)
        return ERR_MEM;     // В случае ошибки в памяти возвращается код ошибки
    glClearColor(0.0, 0.0, 0.0, 0.0);   // Очистка цветового буфера
    glMatrixMode(GL_PROJECTION);        // Установка режима матрицы проекции
    glLoadIdentity();                    // Загрузка единичной матрицы
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);   // Установка ортографической проекции
    glMatrixMode(GL_MODELVIEW);         // Установка режима матрицы модели
    return OK;                          // Возвращение успешного статуса
}

// Функция завершения
void end()
{
    destroy_object(obj);    // Уничтожение объекта
}

// Функция отображения
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   // Очистка цветового буфера
    glColor3f(1.0, 1.0, 1.0);       // Установка цвета

    glLoadIdentity();   // Загрузка единичной матрицы
    glTranslatef(obj->position.translateX, obj->position.translateY, 0.0);   // Трансляция
    glScalef(obj->position.scale, obj->position.scale, obj->position.scale);  // Масштабирование
    glRotatef(obj->position.angleX, 1.0f, 0.0f, 0.0f);   // Вращение по оси X
    glRotatef(obj->position.angleY, 0.0f, 1.0f, 0.0f);   // Вращение по оси Y

    glBegin(GL_LINES);  // Начало рисования линий
    for (int i = 0; i < obj->numEdges; ++i)
    {
        glVertex3fv(obj->vertices[obj->edges[i][0]]);   // Установка вершины
        glVertex3fv(obj->vertices[obj->edges[i][1]]);   // Установка вершины
    }
    glEnd();    // Завершение рисования

    glFlush();  // Принудительная отправка команд рисования в буфер
}

// Функция обработки специальных клавиш
void specialKeys(int key, int x, int y)
{
    (void) x;
    (void) y;
    switch (key)
    {
        case GLUT_KEY_UP:
            obj->position.translateY += 0.1f;  // Смещение вверх
            break;
        case GLUT_KEY_DOWN:
            obj->position.translateY -= 0.1f;  // Смещение вниз
            break;
        case GLUT_KEY_LEFT:
            obj->position.translateX -= 0.1f;  // Смещение влево
            break;
        case GLUT_KEY_RIGHT:
            obj->position.translateX += 0.1f;  // Смещение вправо
            break;
    }
    glutPostRedisplay();    // Перерисовка окна
}

// Функция обработки клавиатурных клавиш
void keyboard(unsigned char key, int x, int y)
{
    (void) x;
    (void) y;
    switch (key)
    {
        case 'w':
            obj->position.angleX += 5.0f;   // Поворот по оси X вверх
            break;
        case 's':
            obj->position.angleX -= 5.0f;   // Поворот по оси X вниз
            break;
        case 'a':
            obj->position.angleY -= 5.0f;   // Поворот по оси Y влево
            break;
        case 'd':
            obj->position.angleY += 5.0f;   // Поворот по оси Y вправо
            break;
        case '+':
            obj->position.scale += 0.1f;    // Увеличение масштаба
            break;
        case '-':
            obj->position.scale -= 0.1f;    // Уменьшение масштаба
            break;
        case 12: // Ctrl+l (12 - ASCII код для Ctrl+l)
            {
                // Выбор файла для загрузки
                system("zenity --file-selection --title='Выберите файл для загрузки' > temp.txt");
                FILE *file = fopen("temp.txt", "r");   // Открытие файла для чтения
                if (file == NULL)
                {
                    printf("Ошибка открытия файла.\n");   // Вывод ошибки, если не удалось открыть файл
                    return;
                }
                char *filename = strRead(file); // Чтение имени файла
                fclose(file);   // Закрытие файла
                if (!filename)
                {
                    printf("Ошибка в названии файла.\n");   // Вывод ошибки, если произошла ошибка в имени файла
                    return;
                }
                int rc = loadModel(filename, obj); // Загрузка модели из файла
                free(filename); // Освобождение памяти из-под имени файла
                remove("temp.txt"); // Удаление временного файла
                switch (rc)
                {
                case OK:
                    printf("Объект успешно загружен\n");   // Вывод сообщения об успешной загрузке объекта
                    break;

                case ERR_FILE_OPEN:
                    printf("Не удалось открыть файл\n");   // Вывод ошибки, если не удалось открыть файл
                    break;

                case ERR_IO:
                    printf("Ошибка данных\n");   // Вывод ошибки данных
                    break;

                case ERR_MEM:
                    printf("Ошибка памяти\n");   // Вывод ошибки памяти
                    break;
                
                default:
                    printf("Неизвестная ошибка\n");   // Вывод неизвестной ошибки
                    break;
                }
            }
            break;
        case 19: // Ctrl+s (19 - ASCII код для Ctrl+s)
            {
                // Выбор файла для сохранения
                system("zenity --file-selection --save --confirm-overwrite --title='Выберите файл для сохранения' > temp.txt");
                FILE *file = fopen("temp.txt", "r");   // Открытие файла для чтения
                if (file == NULL) {
                    printf("Ошибка открытия файла.\n");   // Вывод ошибки, если не удалось открыть файл
                    return;
                }
                char *filename = strRead(file); // Чтение имени файла
                fclose(file);   // Закрытие файла
                if (!filename)
                {
                    printf("Ошибка в названии файла.\n");   // Вывод ошибки, если произошла ошибка в имени файла
                    return;
                }
                int rc = saveModel(filename, obj); // Сохранение модели в файл
                free(filename); // Освобождение памяти из-под имени файла
                remove("temp.txt"); // Удаление временного файла
                switch (rc)
                {
                case OK:
                    printf("Объект успешно выгружен\n");   // Вывод сообщения об успешном сохранении объекта
                    break;

                case ERR_FILE_OPEN:
                    printf("Не удалось открыть файл\n");   // Вывод ошибки, если не удалось открыть файл
                    break;
                
                default:
                    printf("Неизвестная ошибка\n");   // Вывод неизвестной ошибки
                    break;
                }
            }
            break;
    }
    glutPostRedisplay();    // Перерисовка окна
}
