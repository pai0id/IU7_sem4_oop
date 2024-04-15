#include <cstdio>

#include "object.h"

object_t &obj_init(void)
{
    static object_t obj;
    points_init(obj.points);
    edges_init(obj.edges);

    return obj;
}

static err_t read_obj_from_file(object_t &obj, FILE *f)
{
    err_t rc = points_input(obj.points, f);

    if (!rc)
    {
        rc = edges_input(obj.edges, f);
        if (rc)
            points_free(obj.points);
    }

    return rc;
}

void obj_cpy(object_t &dst, const object_t &src)
{
    dst = src;
}

err_t obj_load(object_t &obj, const char *filename)
{
    if (!filename || *filename == '\0')  // Done
        return ERR_FILE_NAME;
    
    FILE *f = fopen(filename, "r");
    if (f == NULL)
        return ERR_FILE_OPEN;  // Done

    object_t tmp = obj_init();

    err_t rc = read_obj_from_file(tmp, f);
    fclose(f);

    if (!rc)
    {
        rc = obj_verify(tmp);

        if (rc)  // Done
        {
            obj_free(tmp);
        }
        else
        {
            obj_free(obj);
            obj_cpy(obj, tmp);
        }
            
    }

    return rc;
}

err_t obj_verify(object_t &obj)
{
    size_t size = get_points_size(obj.points);
    err_t rc = edges_verify(obj.edges, size);
    return rc;
}

err_t obj_draw(const object_t &obj, const scene_t &scene)
{
    clear(scene);
    return edges_draw(scene, obj.edges, obj.points);
}

err_t obj_move(object_t &obj, const move_t &coefs)
{
    return points_move(obj.points, coefs);
}

err_t obj_scale(object_t &obj, point_t &center, const scale_t &coefs)
{
    return points_scale(obj.points, center, coefs);
}

err_t obj_rotate(object_t &obj, point_t &center, const rotate_t &coefs)
{
    return points_rotate(obj.points, center, coefs);
}

void obj_free(object_t &obj)
{
    points_free(obj.points);
    edges_free(obj.edges);
}
