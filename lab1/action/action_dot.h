#ifndef ACTION_DOT_H
#define ACTION_DOT_H

#include <math.h>
#include "error.h"
#include "figure.h"

#define PI 3.1415
#define TO_RADIANS 180.0

/**
 * @brief Структура для представления изменений (вращения, масштабирования и т.д.).
 */
struct action_s
{
    double chg_x; /**< Изменение по оси X. */
    double chg_y; /**< Изменение по оси Y. */
    double chg_z; /**< Изменение по оси Z. */
};

typedef struct action_s action_t;

/**
 * @brief Вывод данных о точках в файл.
 * 
 * @param points_data Массив структур точек.
 * @param points_len Количество точек в массиве.
 * @param file Файл, в который производится вывод.
 */
void print_points_data(const dot_t *points_data, int points_len, FILE *file);

/**
 * @brief Вывод данных о связях между точками в файл.
 * 
 * @param links_data Массив структур связей точек.
 * @param links_len Количество связей в массиве.
 * @param file Файл, в который производится вывод.
 */
void print_links_data(const link_dots_t *links_data, int links_len, FILE *file);

/**
 * @brief Вращение точки вокруг центра на заданные углы.
 * 
 * @param point Указатель на структуру точки.
 * @param center Точка, вокруг которой происходит вращение.
 * @param spin_angles Структура с углами вращения.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t spin_dot(dot_t *point, const dot_t *center, const action_t *spin_angles);

/**
 * @brief Перемещение точки на заданные величины.
 * 
 * @param point Указатель на структуру точки.
 * @param move Структура с величинами перемещения.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t move_dot(dot_t *point, const action_t *move);

/**
 * @brief Масштабирование точки относительно центра на заданные коэффициенты.
 * 
 * @param point Указатель на структуру точки.
 * @param center Точка, относительно которой происходит масштабирование.
 * @param scale Структура с коэффициентами масштабирования.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t scale_dot(dot_t *point, const dot_t *center, const action_t *scale);

#endif /* ACTION_DOT_H */
