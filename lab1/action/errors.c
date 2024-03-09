#include "errors.h"

void catch_error(err_t error)
{
     switch(error)
    {
        case ERR_FILE_OPEN:
            printf("Ошибка: Невозможно открыть файл с данными\n");
            break;
        case ERR_DATA:
            printf("Ошибка: Неверно заданы данные\n");
            break;
        case ERR_MEMORY_ALLOCATE:
            printf("Ошибка: Невозможно выделить память\n");
            break;
        case ERR_NO_FIELD:
            printf("Ошибка: Не выделено поле для отрисовки фигуры\n");
            break;
        case ERR_NO_FIGURE:
            printf("Ошибка: Фигура не задана\n");
            break;
        default:
            printf("Ошибка: Непредвиденная ситуация\n");
            break;
    }
}
