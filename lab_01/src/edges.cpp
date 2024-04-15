#include "edges.h"

void edges_init(edges_t &edges)
{
    edges.arr = NULL;
    edges.size = 0;
}

static err_t read_edges_size(size_t &size, FILE *f)
{
    err_t rc = OK;

    if (fscanf(f, "%zu", &size) != 1)
        rc = ERR_IO;
    else if (size == 0)
        rc = ERR_RANGE;

    return rc;
}

static err_t alloc_edges(edge_t **arr, size_t &size)
{
    err_t rc = OK;

    *arr = (edge_t *)malloc(size * sizeof(edge_t));
    if (*arr == NULL)
        rc = ERR_MEM;

    return rc;
}

static err_t read_edge(edge_t &edge, FILE *f)
{
    err_t rc = OK;
    if (fscanf(f, "%zu %zu", &edge.p1, &edge.p2) != 2)
        rc = ERR_IO;
    return rc;
}

static err_t read_edges_arr(edge_t *arr, size_t size, FILE *f)
{
    err_t rc = OK;

    for (size_t i = 0; !rc && i < size; ++i)
        rc = read_edge(arr[i], f);

    return rc;
}

static void edges_arr_free(edge_t *arr)  // Done
{
    free(arr);
}

err_t edges_input(edges_t &edges, FILE *f)
{
    if (f == NULL || edges.arr != NULL)
        return ERR_PARAM;
    
    err_t rc = OK;
    
    rc = read_edges_size(edges.size, f);  // Done

    if (!rc)
    {
        rc = alloc_edges(&edges.arr, edges.size);  // Done
        if (!rc)
        {
            rc = read_edges_arr(edges.arr, edges.size, f);
            if (rc)
                edges_arr_free(edges.arr);
        }
    }
    return rc;
}

err_t edges_verify(edges_t &edges, size_t &points_size)
{
    if (edges.arr == NULL)
        return ERR_PARAM;

    err_t rc = OK;

    for (size_t i = 0; !rc && i < edges.size; ++i)
    {
        edge_t cur = edges.arr[i];
        if (cur.p1 >= points_size || cur.p2 >= points_size)
            rc = ERR_EDGE;
    }

    return rc;
}

static void edge_draw(const scene_t &scene, const edge_t &edge, const point_t *arr)
{
    point_t p1 = arr[edge.p1];
    point_t p2 = arr[edge.p2];

    draw_line(scene, p1, p2);
}

err_t edges_draw(const scene_t &scene, const edges_t &edges, const points_t &points)
{
    if (edges.arr == NULL || points.arr == NULL)
        return ERR_PARAM;

    for (size_t i = 0; i < edges.size; ++i)
        edge_draw(scene, edges.arr[i], points.arr);

    return OK;
}

void edges_free(edges_t &edges)
{
    free(edges.arr);
    edges.arr = NULL;
    edges.size = 0;
}
