#include "dot.h"


void center_init(dot_t *center) 
{
    center->x = 0;
    center->y = 0;
    center->z = 0;
}

err_t read_connection(link_dots_t *link, FILE *file)
{
    err_t rc = OK;

    if (file == NULL) 
    {
        rc = ERR_FILE_OPEN;
    }
    else if (fscanf(file, "%d%d", &link->point_begin, &link->point_end) != 2) 
    {
        rc = ERR_DATA;
    }

    return rc;
}



err_t read_point(dot_t *dot, FILE *file)
{
    err_t rc = OK;

    if (file == NULL) 
    {
        rc = ERR_FILE_OPEN;
    }
    else if (fscanf(file, "%lf%lf%lf", &dot->x, &dot->y, &dot->z) != 3)
    {
        rc = ERR_DATA;
    }
    return rc;
}

err_t read_single_point(dot_t *points_data, FILE *file, int index)
{
    err_t rc = read_point(&points_data[index], file);
    return rc;
}

