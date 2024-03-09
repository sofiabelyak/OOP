#ifndef DRAW_H
#define DRAW_H

#include "ui_mainwindow.h"

extern "C"
{
    #include "./action/figure.h"
    #include "./action/action.h"
}

using graph_canvas = QGraphicsScene;

/**
 * @brief Структура для представления канваса.
 */
struct canvas_s
{
    graph_canvas *field; /** Указатель на графическую сцену. */
    double width;        /** Ширина */
    double height;       /** Высота */
    QPen pen;            /**Цвет фигуры */
};
using canvas_t = struct canvas_s;

/**
 * @brief Очистка канваса.
 */
void clear_canvas(canvas_t &canvas);

/**
 * @brief Отрисовка фигуры на канвасе.
 * 
 * @param figure Указатель на структуру фигуры.
 * @param canvas Структура для представления канваса.
 * @return Код ошибки (ERR_DATA, OK и т.д.).
 */
err_t draw_figure(figure_t &figure, canvas_t &canvas);



#endif /* DRAW_H */
