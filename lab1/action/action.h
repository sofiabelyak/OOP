#ifndef ACTION_H
#define ACTION_H

#include "figure.h"
#include "action_points_links.h"

/**
 * @brief Тип для представления имени файла.
 */
typedef const char *filename_t;

/**
 * @brief Загрузка данных о фигуре из файла.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param filename Имя файла для загрузки данных.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_DATA, OK и т.д.).
 */
err_t load_figure(figure_t *figure, filename_t filename);

/**
 * @brief Освобождение памяти, занятой структурой фигуры.
 * 
 * @param figure Указатель на структуру фигуры.
 */
void figure_free(figure_t *figure);

/**
 * @brief Поворот фигуры вокруг центра.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param spin_angles Структура с углами поворота.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t spin_figure(figure_t *figure, const action_t *spin_angles);

/**
 * @brief Масштабирование фигуры относительно центра.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param scale_koefs Структура с коэффициентами масштабирования.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t scale_figure(figure_t *figure, const action_t *scale_koefs);

/**
 * @brief Перемещение фигуры в пространстве.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param movements Структура с данными о перемещении.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t move_figure(figure_t *figure, const action_t *movements);

/**
 * @brief Сохранение данных о фигуре в файл.
 * 
 * @param figure Указатель на структуру фигуры.
 * @return Код ошибки (ERR_FILE_OPEN, ERR_DATA, OK и т.д.).
 */
err_t save_figure(const figure_t *figure);

#endif /* ACTION_H */
