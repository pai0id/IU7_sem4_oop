#include "file_sys.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Функция загрузки модели из файла
int loadModel(const char* filename, object_t *obj)
{
    FILE *file = fopen(filename, "r"); // Открытие файла для чтения
    if (file == NULL)
        return ERR_FILE_OPEN;   // Возврат кода ошибки, если не удалось открыть файл
        
    int rc = OK;    // Инициализация статуса выполнения
    GLfloat (*vertices)[3]; // Массив вершин
    GLubyte (*edges)[2];    // Массив рёбер
    int numVertices;    // Количество вершин
    int numEdges;       // Количество рёбер
    GLfloat scale;      // Масштаб

    // Переменные для вычисления минимальных и максимальных координат
    GLfloat minX = 0.0f, minY = 0.0f, minZ = 0.0f;
    GLfloat maxX = 0.0f, maxY = 0.0f, maxZ = 0.0f;

    // Чтение количества вершин из файла
    if (fscanf(file, "%d", &numVertices) != 1)
        rc = ERR_IO;    // В случае ошибки ввода-вывода устанавливается соответствующий статус
    if (!rc)
    {
        // Выделение памяти под массив вершин
        vertices = (GLfloat (*)[3])malloc(numVertices * sizeof(GLfloat[3]));
        if (!vertices)
            rc = ERR_MEM;   // В случае ошибки выделения памяти устанавливается соответствующий статус
    }
    
    // Чтение вершин из файла
    if (!rc)
    {
        for (int i = 0; i < numVertices; ++i)
        {
            if (fscanf(file, "%f %f %f", &vertices[i][0], &vertices[i][1], &vertices[i][2]) != 3)
            {
                free(vertices); // Освобождение памяти, если чтение не удалось
                rc = ERR_IO;    // Установка статуса ошибки
                break;
            }
            // Вычисление минимальных и максимальных координат
            if (i == 0)
            {
                minX = maxX = vertices[i][0];
                minY = maxY = vertices[i][1];
                minZ = maxZ = vertices[i][2];
            }
            else
            {
                if (vertices[i][0] < minX) minX = vertices[i][0];
                if (vertices[i][0] > maxX) maxX = vertices[i][0];
                if (vertices[i][1] < minY) minY = vertices[i][1];
                if (vertices[i][1] > maxY) maxY = vertices[i][1];
                if (vertices[i][2] < minZ) minZ = vertices[i][2];
                if (vertices[i][2] > maxZ) maxZ = vertices[i][2];
            }
        }
    }
    // Вычисление центра и масштаба объекта
    if (!rc)
    {
        GLfloat centerX = (minX + maxX) / 2.0f;
        GLfloat centerY = (minY + maxY) / 2.0f;
        GLfloat centerZ = (minZ + maxZ) / 2.0f;

        GLfloat sizeX = maxX - minX;
        GLfloat sizeY = maxY - minY;
        GLfloat sizeZ = maxZ - minZ;

        GLfloat maxSize = sizeX;
        if (sizeY > maxSize) maxSize = sizeY;
        if (sizeZ > maxSize) maxSize = sizeZ;
        scale = 2.0f / maxSize;

        // Нормализация координат вершин
        for (int i = 0; i < numVertices; ++i)
        {
            vertices[i][0] -= centerX;
            vertices[i][1] -= centerY;
            vertices[i][2] -= centerZ;
        }
    }

    // Чтение количества рёбер из файла
    if (!rc)
    {
        if (fscanf(file, "%d", &numEdges) != 1)
        {
            free(vertices); // Освобождение памяти
            rc = ERR_IO;    // Установка статуса ошибки
        }
    }
    // Выделение памяти под массив рёбер
    if (!rc)
    {
        edges = (GLubyte (*)[2])malloc(numEdges * sizeof(GLubyte[2]));
        if (!edges)
        {
            free(vertices); // Освобождение памяти
            rc = ERR_MEM;   // Установка статуса ошибки
        }
    }
    // Чтение рёбер из файла
    if (!rc)
    {
        for (int i = 0; i < numEdges; ++i)
        {
            if (fscanf(file, "%hhu %hhu", &edges[i][0], &edges[i][1]) != 2)
            {
                free(edges);    // Освобождение памяти
                free(vertices); // Освобождение памяти
                rc = ERR_IO;    // Установка статуса ошибки
            }
        }
    }

    // Если загрузка прошла успешно, обновляем объект
    if (!rc)
    {
        reset_object(obj);      // Сброс объекта
        obj->numVertices = numVertices;    // Установка количества вершин
        obj->vertices = vertices;           // Установка массива вершин
        obj->numEdges = numEdges;           // Установка количества рёбер
        obj->edges = edges;                 // Установка массива рёбер
        obj->position.scale = scale;        // Установка масштаба
    }

    fclose(file);   // Закрытие файла
    return rc;      // Возврат статуса выполнения
}

// Функция сохранения модели в файл
int saveModel(const char* filename, object_t *obj)
{
    FILE *file = fopen(filename, "w"); // Открытие файла для записи
    if (file == NULL)
        return ERR_FILE_OPEN;   // Возврат кода ошибки, если не удалось открыть файл

    // Запись количества вершин в файл
    fprintf(file, "%d\n", obj->numVertices);
    // Запись вершин в файл
    for (int i = 0; i < obj->numVertices; ++i)
        fprintf(file, "%f %f %f\n", obj->vertices[i][0], obj->vertices[i][1], obj->vertices[i][2]);

    // Запись количества рёбер в файл
    fprintf(file, "%d\n", obj->numEdges);
    // Запись рёбер в файл
    for (int i = 0; i < obj->numEdges; ++i)
        fprintf(file, "%hhu %hhu\n", obj->edges[i][0], obj->edges[i][1]);

    fclose(file);   // Закрытие файла
    return OK;      // Возврат успешного статуса выполнения
}
