#include "draw.h"

err_t draw_line_func_parse(const dot_t &point1, const dot_t &point2, canvas_t &canvas)
{
    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }
    canvas.field->addLine(point1.x, point1.y, point2.x, point2.y, canvas.pen);
    return OK;
}

dot_t transform_point(const dot_t &point, const canvas_t &canvas)
{
    return {point.x + canvas.width / 2, point.y + canvas.height / 2, point.z};
}

static err_t get_link_points(dot_t &point1, dot_t &point2, const points_t &points, const links_t &links, int link_index)
{
    err_t rc = OK;

    if ((points.data == NULL) || (links.data == NULL))
    {
        rc = ERR_MEMORY_ALLOCATE;
    }
    else if (link_index < 0 || link_index >= links.len)
    {
        rc = ERR_DATA;
    }
    else
    {
        const link_dots_t &link = links.data[link_index];

        if (link.point_begin < 0 || link.point_begin >= points.len || link.point_end < 0 || link.point_end >= points.len)
        {
            rc = ERR_DATA;
        }
        else
        {
            point1 = points.data[link.point_begin];
            point2 = points.data[link.point_end];
        }
    }

    return rc;
}


err_t check(const points_t &a, const links_t &b)
{
    if ((a.data == NULL) || (b.data == NULL))
    {
        return ERR_MEMORY_ALLOCATE;
    }
    return OK;
}
static err_t draw_figure_side(const figure_t &figure, int link_index, canvas_t &canvas)
{
    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }
    const points_t &a = figure.points;
    const links_t &b = figure.links;
    err_t rc = check(a, b);
    if (rc == OK)
    {
        dot_t point1, point2;
        rc = get_link_points(point1, point2, a, b, link_index);
        if (rc == OK)
        {
            dot_t transformedPoint1 = transform_point(point1, canvas);
            dot_t transformedPoint2 = transform_point(point2, canvas);

            rc = draw_line_func_parse(transformedPoint1, transformedPoint2, canvas);
        }
    }
    return rc;
}



int len(const figure_t &figure)
{
    links_t len_lin = figure.links;
    return len_lin.len;
}

err_t draw_object(const figure_t &figure, canvas_t &canvas)
{
    err_t rc = OK;
    int links_len = len(figure);
    for (int i = 0; rc == OK && i < links_len; i++)
    {
        rc = draw_figure_side(figure, i, canvas);
    }
    return rc;
}

err_t check_links_and_points(figure_t &figure)
{
    points_t a = figure.points;
    links_t b = figure.links;
    if ((a.data == NULL) || (b.data == NULL))
    {
        return ERR_MEMORY_ALLOCATE;
    }
    return OK;
}

err_t check_canvas(canvas_t &canvas)
{
    if (canvas.field == NULL)
    {
        return ERR_NO_FIELD;
    }
    return OK;
}

err_t draw_figure(figure_t &figure, canvas_t &canvas)
{
    err_t rc = OK;

    if ((rc = check_links_and_points(figure)) != ERR_MEMORY_ALLOCATE && (rc = check_canvas(canvas)) != ERR_NO_FIELD)
    {
        clear_canvas(canvas);
        rc = draw_object(figure, canvas);
    }
    return rc;
}

void clear_canvas(canvas_t &canvas)
{
    canvas.field->clear();
}
