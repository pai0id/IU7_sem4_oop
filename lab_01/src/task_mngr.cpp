#include "task_mngr.h"

err_t process_task(task_t &task)
{
    err_t rc = OK;
    static object_t obj = obj_init();

    switch (task.action)
    {
        case MOVE:
            rc = obj_move(obj, task.move_coefs);
            break;
        case SCALE:
            rc = obj_scale(obj, task.center, task.scale_coefs);
            break;
        case ROTATE:
            rc = obj_rotate(obj, task.center, task.rotate_coefs);
            break;
        case LOAD:
            rc = obj_load(obj, task.filename);
            break;
        case DRAW:
            rc = obj_draw(obj, task.scene);
            break;
        case DESTROY:
            obj_free(obj);
            break;
        default:
            rc = ERR_TASK;
            break;
    }

    return rc;
}
