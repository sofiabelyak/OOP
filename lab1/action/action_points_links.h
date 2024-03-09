#ifndef ACTION_POINTS_LINKS_H
#define ACTION_POINTS_LINKS_H

#include "figure.h"
#include "action_dot.h"

/**
 * @brief Вращение массива точек вокруг центра на заданные углы.
 * 
 * @param points Указатель на структуру точек.
 * @param center Точка, вокруг которой происходит вращение.
 * @param spin_angles Структура с углами вращения.
 * @return Код ошибки (ERR_NO_FIGURE, OK и т.д.).
 */
err_t spin_points_array(points_t *points, const dot_t *center, const action_t *spin_angles);

/**
 * @brief Масштабирование массива точек относительно центра на заданные коэффициенты.
 * 
 * @param points Указатель на структуру точек.
 * @param center Точка, относительно которой происходит масштабирование.
 * @param scale_koefs Структура с коэффициентами масштабирования.
 * @return Код ошибки (ERR_NO_FIGURE, OK и т.д.).
 */
err_t scale_points_array(points_t *points, const dot_t *center, const action_t *scale_koefs);

/**
 * @brief Перемещение массива точек на заданные величины.
 * 
 * @param points Указатель на структуру точек.
 * @param movements Структура с величинами перемещения.
 * @return Код ошибки (ERR_NO_FIGURE, OK и т.д.).
 */
err_t move_points_array(points_t *points, const action_t *movements);

#endif /* ACTION_POINTS_LINKS_H */
