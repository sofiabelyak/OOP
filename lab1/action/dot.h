#ifndef DOT_H
#define DOT_H

#include "stdio.h"
#include "stdlib.h"
#include "errors.h"

/**
 * @brief Структура для представления трехмерной точки.
 */
typedef struct {
    double x, y, z; /**< Координаты точки по осям X, Y и Z. */
} dot_t;

/**
 * @brief Структура для представления связи между двумя точками.
 */
typedef struct {
    int point_begin, point_end; /**< Начальная и конечная точки связи. */
} link_dots_t;

/**
 * @brief Инициализация центра фигуры.
 * 
 * @param center Указатель на структуру точки, представляющей центр фигуры.
 */
void center_init(dot_t *center);

/**
 * @brief Чтение данных о связи между двумя точками из файла.
 * 
 * @param link Указатель на структуру связи между точками.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_connection(link_dots_t *link, FILE *file);

/**
 * @brief Чтение данных о точке из файла.
 * 
 * @param dot Указатель на структуру точки.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_point(dot_t *dot, FILE *file);

/**
 * @brief Чтение данных о единичной точке из файла и сохранение их в массиве точек.
 * 
 * @param points_data Указатель на массив точек.
 * @param file Файл, из которого производится чтение.
 * @param index Индекс точки в массиве.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_single_point(dot_t *points_data, FILE *file, int index);

#endif
