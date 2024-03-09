#include "action_dot.h"
#include <math.h>

void print_points_data(const dot_t *points_data, int points_len, FILE *file)
{
    for (int i = 0; i < points_len; i++)
        fprintf(file, "%lf%lf%lf\n", points_data[i].x, points_data[i].y, points_data[i].z);
}

void print_links_data(const link_dots_t *links_data, int links_len, FILE *file)
{
    for (int i = 0; i < links_len; i++)
        fprintf(file, "%d%d\n", links_data[i].point_begin, links_data[i].point_end);
}

inline double to_radians(const double angle) {
    return angle * (PI / TO_RADIANS);
}

static void rotate_x(dot_t *point, const dot_t *r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double y = point->y;

    point->y = (point->y - r_center->y) * r_cos + (point->z - r_center->z) * r_sin + r_center->y;
    point->z = -(y - r_center->y) * r_sin + (point->z - r_center->z) * r_cos + r_center->z;
}

static void rotate_y(dot_t *point, const dot_t *r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point->x;

    point->x = (point->x - r_center->x) * r_cos + (point->z - r_center->z) * r_sin + r_center->x;
    point->z = -(x - r_center->x) * r_sin + (point->z - r_center->z) * r_cos + r_center->z;
}

static void rotate_z(dot_t *point, const dot_t *r_center, const double angle)
{
    double r_cos = cos(to_radians(angle));
    double r_sin = sin(to_radians(angle));
    double x = point->x;

    point->x = (point->x - r_center->x) * r_cos + (point->y - r_center->y) * r_sin + r_center->x;
    point->y = -(x - r_center->x) * r_sin + (point->y - r_center->y) * r_cos + r_center->y;
}

err_t spin_dot(dot_t *point, const dot_t *center, const action_t *spin_angles)
{
    rotate_x(point, center, spin_angles->chg_x);
    rotate_y(point, center, spin_angles->chg_y);
    rotate_z(point, center, spin_angles->chg_z);

    return OK;
}

err_t scale_dot(dot_t *point, const dot_t *center, const action_t *scale)
{
    point->x = point->x * scale->chg_x + (1 - scale->chg_x) * center->x;
    point->y = point->y * scale->chg_y + (1 - scale->chg_y) * center->y;
    point->z = point->z * scale->chg_z + (1 - scale->chg_z) * center->z;

    return OK;
}

err_t move_dot(dot_t *point, const action_t *move)
{
    point->x += move->chg_x;
    point->y += move->chg_y;
    point->z += move->chg_z;

    return OK;
}
