#include "points_links.h"
void links_init(links_t *links) 
{
    links->data = NULL;
    links->len = 0;
}

void free_links(links_t *links) 
{
    free(links->data);
    links->len = 0;
}

err_t allocate_connections_arr(links_t *links) 
{
    links->data = (link_dots_t *)malloc(links->len * sizeof(link_dots_t));
    if (links->data == NULL)
    {
        return ERR_MEMORY_ALLOCATE;
    }
    return OK;
}

void points_init(points_t *points) 
{
    points->data = NULL;
    points->len = 0;
}

err_t allocate_points(points_t *points)
{
    points->data = (dot_t *)malloc(points->len * sizeof(dot_t));
    if (points->data == NULL)
        return ERR_MEMORY_ALLOCATE;
    return OK;
}

void free_points(points_t *points) 
{
    free(points->data);
    points->len = 0;
}

err_t read_all_dots(points_t *points, FILE *file)
{
    err_t rc = OK;
    for (int i = 0;rc == OK && i < points->len; i++) 
    {
        rc = read_single_point(points->data, file, i);
    }
    return rc;
}

err_t read_amount(int *amount, FILE *file)
{
    err_t rc = OK;

    if (file == NULL) 
    {
        rc = ERR_FILE_OPEN;
    }
    else if (fscanf(file, "%d", amount) != 1)
    {
        rc = ERR_DATA;
    }
    return rc;
}



err_t read_points(points_t *points, FILE *file)
{
    if (file == NULL)
        return ERR_FILE_OPEN;
    int amount = 0;
    err_t rc = read_amount(&amount, file);
    if (rc == OK)
    {
        points->len = amount;
        rc = allocate_points(points);
        if (rc == OK)
        {
            rc = read_all_dots(points, file);
            if (rc != OK)
                free_points(points);
        }
    }
    return rc;
}

err_t read_single_connection(links_t *links, FILE *file, int index)
{
    err_t rc = read_connection(&links->data[index], file);
    return rc;
}
void free_connections_arr(links_t *links)
{
    free(links->data);
}

err_t read_dots_connections(links_t *links, FILE *file)
{
    if (file == NULL)
        return ERR_FILE_OPEN;
    int amount = 0;
    err_t rc = read_amount(&amount, file);
    if (rc == OK) {
        links->len = amount;
        rc = allocate_connections_arr(links);
        if (rc == OK) {
            for (int i = 0;rc == OK && i < amount; i++) {
                rc = read_single_connection(links, file, i);
            }
            if (rc != OK)
                free_connections_arr(links);
        }
    }
    return rc;
}