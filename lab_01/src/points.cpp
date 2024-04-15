#include <cstdlib>
#include <cmath>

#include "points.h"

size_t get_points_size(const points_t &points)
{
    return points.size;
}

void points_init(points_t &points)
{
    points.arr = NULL;
    points.size = 0;
}

static err_t read_points_size(size_t &size, FILE *f)
{
    err_t rc = OK;

    if (fscanf(f, "%zu", &size) != 1)
        rc = ERR_IO;
    else if (size < 2)
        rc = ERR_RANGE;

    return rc;
}

static err_t alloc_points(point_t **arr, size_t &size)
{
    err_t rc = OK;

    *arr = (point_t *)malloc(size * sizeof(point_t));
    if (*arr == NULL)
        rc = ERR_MEM;

    return rc;
}

static err_t read_point(point_t &point, FILE *f)
{
    err_t rc = OK;
    if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        rc = ERR_IO;
    return rc;
}

static err_t read_points_arr(point_t *arr, size_t size, FILE *f)
{
    err_t rc = OK;

    for (size_t i = 0; !rc && i < size; ++i)
        rc = read_point(arr[i], f);

    return rc;
}

static void points_arr_free(point_t *arr) // Done
{
    free(arr);
}

err_t points_input(points_t &points, FILE *f)
{
    if (f == NULL || points.arr != NULL)
        return ERR_PARAM;
    
    err_t rc = OK;

    rc = read_points_size(points.size, f);  // Done

    if (!rc)
    {
        rc = alloc_points(&points.arr, points.size);  // Done
        if (!rc)
        {
            rc = read_points_arr(points.arr, points.size, f);
            if (rc)
                points_arr_free(points.arr);
        }
    }
    return rc;
}

static void point_move(point_t &point, const move_t &coefs)
{
    point.x += coefs.dx;
    point.y += coefs.dy;
    point.z += coefs.dz;
}

err_t points_move(points_t &points, const move_t &coefs)
{
    if (points.arr == NULL)
        return ERR_PARAM;

    for (size_t i = 0; i < points.size; ++i)
        point_move(points.arr[i], coefs);

    return OK;
}

static void point_scale(point_t &point, const point_t &center, const scale_t &coefs)
{
    point.x = coefs.kx * point.x + (1 - coefs.kx) * center.x;
    point.y = coefs.ky * point.y + (1 - coefs.ky) * center.y;
    point.z = coefs.kz * point.z + (1 - coefs.kz) * center.z;
}

err_t points_scale(points_t &points, const point_t &center, const scale_t &coefs)
{
    if (points.arr == NULL)
        return ERR_PARAM;

    for (size_t i = 0; i < points.size; ++i)
        point_scale(points.arr[i], center, coefs);

    return OK;
}

static double deg_to_rad(double angle)
{
    return angle * M_PI / 180.0;
}

static void set_coords_local(point_t &point, const point_t &center)
{
    move_t local_scale = {-center.x, -center.y, -center.y};
    point_move(point, local_scale);
}

static void set_coords_global(point_t &point, const point_t &center)
{
    move_t global_scale = {center.x, center.y, center.y};
    point_move(point, global_scale);
}

static void rotate_around_x(point_t &point, double angle)
{
    angle = deg_to_rad(angle);
    double y = point.y * cos(angle) - point.z * sin(angle);
    double z = point.y * sin(angle) + point.z * cos(angle);
    point.y = y;
    point.z = z;
}

static void rotate_around_y(point_t &point, double angle)
{
    angle = deg_to_rad(angle);
    double x = point.x * cos(angle) + point.z * sin(angle);
    double z = -point.x * sin(angle) + point.z * cos(angle);
    point.x = x;
    point.z = z;
}

static void rotate_around_z(point_t &point, double angle)
{
    angle = deg_to_rad(angle);
    double x = point.x * cos(angle) - point.y * sin(angle);
    double y = point.x * sin(angle) + point.y * cos(angle);
    point.x = x;
    point.y = y;
}

static void point_rotate(point_t &point, const point_t &center, const rotate_t &coefs)
{
    set_coords_local(point, center);
    rotate_around_x(point, coefs.ax);
    rotate_around_y(point, coefs.ay);
    rotate_around_z(point, coefs.az);
    set_coords_global(point, center);
}

err_t points_rotate(points_t &points, const point_t &center,  const rotate_t &coefs)
{
    if (points.arr == NULL)
        return ERR_PARAM;

    for (size_t i = 0; i < points.size; ++i)
        point_rotate(points.arr[i], center, coefs);

    return OK;
}

void points_free(points_t &points)
{
    free(points.arr);
    points.arr = NULL;
    points.size = 0;
}
