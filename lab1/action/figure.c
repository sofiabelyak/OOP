#include "figure.h"

figure_t figure_init(void)
{
    figure_t figure;
    figure.points.data = NULL;
    figure.points.len = 0;
    center_init(&figure.center);
    links_init(&figure.links);
    return figure;
}


err_t read_figure(figure_t *figure, FILE *file)
{
    if (file == NULL)
        return ERR_FILE_OPEN;
    *figure = figure_init();
    err_t rc = read_points(&figure->points, file);
    if (rc == OK)
    {
        rc = read_dots_connections(&figure->links, file);
        if (rc != OK)
            free_points(&figure->points);
    }
    return rc;
}
