#ifndef POINTS_LINKS_H
#define POINTS_LINKS_H

#include "dot.h"

/**
 * @brief Структура для представления массива точек и их количества.
 */
typedef struct {
    dot_t *data; /**< Указатель на массив точек. */
    int len;     /**< Количество точек в массиве. */
} points_t;

/**
 * @brief Структура для представления массива связей и их количества.
 */
typedef struct {
    link_dots_t *data; /**< Указатель на массив связей. */
    int len;           /**< Количество связей в массиве. */
} links_t;

/**
 * @brief Инициализация массива связей.
 * 
 * @param links Указатель на структуру массива связей.
 */
void links_init(links_t *links);

/**
 * @brief Освобождение памяти, занятой массивом связей.
 * 
 * @param links Указатель на структуру массива связей.
 */
void free_links(links_t *links);

/**
 * @brief Выделение памяти под массив связей.
 * 
 * @param links Указатель на структуру массива связей.
 * @return Код ошибки (ERR_MEMORY_ALLOCATE, OK и т.д.).
 */
err_t allocate_connections_arr(links_t *links);

/**
 * @brief Инициализация массива точек.
 * 
 * @param points Указатель на структуру массива точек.
 */
void points_init(points_t *points);

/**
 * @brief Выделение памяти под массив точек.
 * 
 * @param points Указатель на структуру массива точек.
 * @return Код ошибки (ERR_MEMORY_ALLOCATE, OK и т.д.).
 */
err_t allocate_points(points_t *points);

/**
 * @brief Освобождение памяти, занятой массивом точек.
 * 
 * @param points Указатель на структуру массива точек.
 */
void free_points(points_t *points);

/**
 * @brief Чтение данных о всех точках из файла.
 * 
 * @param points Указатель на структуру массива точек.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_all_dots(points_t *points, FILE *file);

/**
 * @brief Чтение количества точек из файла.
 * 
 * @param amount Указатель на переменную для хранения количества точек.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_amount(int *amount, FILE *file);

/**
 * @brief Чтение данных о точках из файла.
 * 
 * @param points Указатель на структуру массива точек.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_points(points_t *points, FILE *file);

/**
 * @brief Чтение данных о связях между точками из файла.
 * 
 * @param links Указатель на структуру массива связей.
 * @param file Файл, из которого производится чтение.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_FILE_ERROR, ERR_DATA, OK и т.д.).
 */
err_t read_dots_connections(links_t *links, FILE *file);

#endif
