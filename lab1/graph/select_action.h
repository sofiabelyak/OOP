#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "draw.h"


using filename_t = const char *;

/**
 * @brief Перечисление для возможных действий (рисование, загрузка и т.д.).
 */
enum Actions
{
    DRAW,  /**< Действие: Рисование. */
    LOAD,  /**< Действие: Загрузка. */
    SCALE, /**< Действие: Масштабирование. */
    SPIN,  /**< Действие: Вращение. */
    MOVE,  /**< Действие: Перемещение. */
    SAVE,  /**< Действие: Сохранение. */
    QUIT   /**< Действие: Завершение. */
};

/**
 * @brief Структура для представления события (например, действия пользователя).
 */
struct user_interaction
{
    canvas_t canvas;    /**< Структура для представления канваса. */
    action_t change;    /**< Структура для представления изменений. */
    filename_t file_name; /**< Имя файла для операций загрузки/сохранения. */
};
using user_interaction_t = struct user_interaction;

/**
 * @brief Выбор действия в зависимости от переданного кода действия.
 * 
 * @param action Код действия (например, DRAW, LOAD и т.д.).
 * @param event Структура для представления события.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t select_action(Actions action, user_interaction_t event);

#endif