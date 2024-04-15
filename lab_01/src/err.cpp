#include <cstdio>

#include "err.h"

void print_err_msg(const err_t err)
{
    switch (err)
    {
        case OK:
            break;
        case ERR_IO:
            printf("IO error occured\n");
            break;
        case ERR_MEM:
            printf("IO error occured\n");
            break;
        case ERR_FILE_OPEN:
            printf("Error occured while opening file\n");
            break;
        case ERR_FILE_NAME:
            printf("Incorrect file name\n");
            break;
        case ERR_RANGE:
            printf("Range error\n");
            break;
        case ERR_UI:
            printf("UI error\n");
            break;
        case ERR_TASK:
            printf("Incorrect task\n");
            break;
        case ERR_PARAM:
            printf("Incorrect func param\n");
            break;
        case ERR_EDGE:
            printf("Incorrect object format\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }
}
