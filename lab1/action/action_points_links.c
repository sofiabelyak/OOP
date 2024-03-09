#include "action_points_links.h"

err_t spin_points_array(points_t *points, const dot_t *center, const action_t *spin_angles)
{
    if (points->data == NULL)
        return ERR_NO_FIGURE;
    err_t rc = OK;
    for (int i = 0;rc == OK && i < points->len; i++)
        rc = spin_dot(points->data + i, center, spin_angles);
    return rc;
}



err_t scale_points_array(points_t *points, const dot_t *center, const action_t *scale_koefs)
{
    if (points->data == NULL)
        return ERR_NO_FIGURE;
    err_t rc = OK;
    for (int i = 0; rc == OK && i < points->len; i++)
        rc = scale_dot(points->data + i, center, scale_koefs);
    return rc;
}



err_t move_points_array(points_t *points, const action_t *movements)
{
    if (points->data == NULL)
        return ERR_NO_FIGURE;
    err_t rc = OK;
    for (int i = 0;rc == OK && i < points->len; i++)
        rc = move_dot(points->data + i, movements);

    return rc;
}
