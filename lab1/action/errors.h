#ifndef ERRORS_H
#define ERRORS_H

/**
 * @brief Перечисление для кодов ошибок.
 */
enum Errors
{
    OK,                  /**< Операция выполнена успешно. */
    ERR_FILE_OPEN,       /**< Ошибка при открытии файла. */
    ERR_DATA,            /**< Ошибка в данных (например, некорректный формат). */
    ERR_MEMORY_ALLOCATE, /**< Ошибка при выделении памяти. */
    ERR_NO_FIELD,        /**< Отсутствует необходимое поле. */
    ERR_NO_FIGURE,       /**< Отсутствует фигура или ее часть. */
    ERR_EXTRA_ERROR,     /**< Дополнительная неопределенная ошибка. */
    ERR_FILE_ERROR       /**< Ошибка файла. */
};

typedef enum Errors err_t; /**< Псевдоним для перечисления кодов ошибок. */

/**
 * @brief Вывод сообщения о возникшей ошибке.
 * 
 * @param error Код ошибки.
 */
void catch_error(err_t error);

#endif /* ERRORS_H */
