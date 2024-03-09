#include "action.h"

void figure_free(figure_t *figure)
{
    free_points(&figure->points);
    free_links(&figure->links);
}

err_t copy_figure(const figure_t *source, figure_t *dst)
{
    err_t rc = OK;

    if (source == NULL || dst == NULL)
        rc = ERR_DATA;
    else
    {
        dst->center = source->center;
        dst->points.len = source->points.len;
        dst->links.len = source->links.len;
        dst->points.data = (dot_t *)malloc(dst->points.len * sizeof(dot_t));
        dst->links.data = (link_dots_t *)malloc(dst->links.len * sizeof(link_dots_t));
        if (dst->points.data == NULL)
        {
            rc = ERR_MEMORY_ALLOCATE;
        }
        else if (dst->links.data == NULL)
        {
            free(dst->points.data);
            dst->points.len = 0;
            rc = ERR_MEMORY_ALLOCATE;
        } 
        else 
        {
            for (int i = 0; i < source->points.len; ++i)
                dst->points.data[i] = source->points.data[i];

            for (int i = 0; i < source->links.len; ++i)
                dst->links.data[i] = source->links.data[i];
        }
    }
    return rc;
}

err_t load_figure(figure_t *figure, filename_t filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return ERR_FILE_OPEN;
    if (ferror(file))
    {
        fclose(file);
        return ERR_FILE_ERROR;
    }
    figure_t temp_figure;
    err_t rc = read_figure(&temp_figure, file);
    fclose(file);
    if (rc == OK)
    {
        figure_free(figure);
        rc = copy_figure(&temp_figure, figure);
    }
    return rc;
}



void print_figure(const figure_t *figure, FILE *file)
{
    fprintf(file, "%d\n", figure->points.len);
    print_points_data(figure->points.data, figure->points.len, file);

    fprintf(file, "%d\n", figure->links.len);
    print_links_data(figure->links.data, figure->links.len, file);
}


err_t save_figure(const figure_t *figure)
{
    FILE *file = fopen("res.txt", "w");
    err_t rc = ERR_FILE_OPEN;
    if (file == NULL)
        return rc;
    if (ferror(file))
    {
        fclose(file);
        return ERR_FILE_ERROR;
    }
    rc = OK;
    print_figure(figure, file);
    fclose(file);
    return rc;
}



err_t spin_figure(figure_t *figure, const action_t *spin_angles)
{
    err_t rc = spin_points_array(&figure->points, &figure->center, spin_angles);
    return rc;
}



err_t scale_figure(figure_t *figure, const action_t *scale_koefs)
{
    err_t rc = scale_points_array(&figure->points, &figure->center, scale_koefs);
    return rc;
}


err_t move_figure(figure_t *figure, const action_t *movements)
{
    err_t rc = move_points_array(&figure->points, movements);
    if (rc == OK)
        move_dot(&figure->center, movements);

    return rc;
}

