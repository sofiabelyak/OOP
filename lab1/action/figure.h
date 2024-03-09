#ifndef FIGURE_H
#define FIGURE_H
#include "points_links.h"

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

/**
 * @brief Структура для представления трехмерной фигуры, состоящей из точек и связей.
 */
typedef struct {
    points_t points; /**< Структура для точек. */
    dot_t center;    /**< Центр фигуры. */
    links_t links;   /**< Структура для связей между точками. */
} figure_t;

/**
 * @brief Инициализация структуры фигуры.
 * 
 * @return Инициализированная структура фигуры.
 */
figure_t figure_init(void);


/**
 * @brief Считывание данных о фигуре из файла.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param file Указатель на открытый файл для чтения.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_DATA, OK и т.д.).
 */
err_t read_figure(figure_t *figure, FILE *file);

#endif /* FIGURE_H */
