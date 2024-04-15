#include <cstdio>

#include "UI.h"
#include "draw.h"
#include "object_pos.h"
#include "task_mngr.h"
#include "str_read.h"

static struct
{
    point_t center;
    move_t move_coefs;
    scale_t scale_coefs;
    rotate_t rotate_coefs;
} ui;

static void ui_reset(void)
{
    ui.move_coefs.dx = 0;
    ui.move_coefs.dy = 0;
    ui.move_coefs.dz = 0;

    ui.scale_coefs.kx = 0;
    ui.scale_coefs.ky = 0;
    ui.scale_coefs.kz = 0;

    ui.rotate_coefs.ax = 0;
    ui.rotate_coefs.ay = 0;
    ui.rotate_coefs.az = 0;
}

err_t init(SDL_Window **window, SDL_Renderer **renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return ERR_UI;
    }

    *window = SDL_CreateWindow("Geometry Canvas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return ERR_UI;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return ERR_UI;
    }
    ui_reset();
    return OK;
}

err_t draw_scene(SDL_Renderer *renderer)
{
    scene_t scene;
    scene.renderer = renderer;
    scene.width = WINDOW_WIDTH;
    scene.height = WINDOW_HEIGHT;
    scene.bg_color = SDL_BLACK;
    scene.draw_color = SDL_GREEN;

    task_t cur_task;
    cur_task.action = DRAW;
    cur_task.scene = scene;

    err_t rc = process_task(cur_task);
    SDL_RenderPresent(renderer);

    return rc;
}

static char *get_file_name()
{
    system("zenity --file-selection --title='Выберите файл для загрузки' > temp.txt");
    FILE *file = fopen("temp.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия файла.\n");
        return NULL;
    }
    char *filename = str_read(file);
    fclose(file);
    if (!filename)
        printf("Ошибка в названии файла.\n");
    return filename;
}

static void load_obj(SDL_Renderer *renderer)
{
    char *filename = get_file_name();
    if (!filename)
    {
        print_err_msg(ERR_FILE_OPEN);
        return;
    }
    task_t cur_task;
    cur_task.action = LOAD;
    cur_task.filename = filename;

    err_t rc = process_task(cur_task);
    free(filename);

    if (rc)
    {
        print_err_msg(rc);
        return;
    }

    rc = draw_scene(renderer);
    print_err_msg(rc);
}

static void move_obj(SDL_Renderer *renderer)
{
    move_t coefs;
    coefs.dx = ui.move_coefs.dx;
    coefs.dy = ui.move_coefs.dy;
    coefs.dz = ui.move_coefs.dz;

    task_t cur_task;
    cur_task.action = MOVE;
    cur_task.move_coefs = coefs;

    err_t rc = process_task(cur_task);

    if (rc)
    {
        print_err_msg(rc);
        return;
    }

    rc = draw_scene(renderer);
    print_err_msg(rc);
}

static void scale_obj(SDL_Renderer *renderer)
{
    point_t center;
    center.x = ui.center.x;
    center.y = ui.center.y;
    center.z = ui.center.z;
    
    scale_t coefs;
    coefs.kx = ui.scale_coefs.kx;
    coefs.ky = ui.scale_coefs.ky;
    coefs.kz = ui.scale_coefs.kz;

    task_t cur_task;
    cur_task.action = SCALE;
    cur_task.center = center;
    cur_task.scale_coefs = coefs;

    err_t rc = process_task(cur_task);

    if (rc)
    {
        print_err_msg(rc);
        return;
    }

    rc = draw_scene(renderer);
    print_err_msg(rc);
}

static void rotate_obj(SDL_Renderer *renderer)
{
    point_t center;
    center.x = ui.center.x;
    center.y = ui.center.y;
    center.z = ui.center.z;
    
    rotate_t coefs;
    coefs.ax = ui.rotate_coefs.ax;
    coefs.ay = ui.rotate_coefs.ay;
    coefs.az = ui.rotate_coefs.az;

    task_t cur_task;
    cur_task.action = ROTATE;
    cur_task.center = center;
    cur_task.rotate_coefs = coefs;

    err_t rc = process_task(cur_task);

    if (rc)
    {
        print_err_msg(rc);
        return;
    }

    rc = draw_scene(renderer);
    print_err_msg(rc);
}

static void stdin_fix(void)
{
    char tmp[3];
    while(fgets(tmp, sizeof(tmp), stdin));
}

static void get_center(void)
{
    char tags[] = {'x', 'y', 'z'};
    double vals[3];
    for (size_t i = 0; i < 3; ++i)
    {
        while (1)
        {
            printf("Введите %c центра поворота/масштабирования: ", tags[i]);
            if (scanf("%lf", &vals[i]) == 1)
                break;
            else
                printf("Некорректно\n");
            stdin_fix();
        }
    }
    ui.center.x = vals[0];
    ui.center.y = vals[1];
    ui.center.z = vals[2];
}

static void get_move_coefs(void)
{
    char tags[] = {'x', 'y', 'z'};
    double vals[3];
    for (size_t i = 0; i < 3; ++i)
    {
        while (1)
        {
            printf("Введите d%c: ", tags[i]);
            if (scanf("%lf", &vals[i]) == 1)
                break;
            else
                printf("Некорректно\n");
            stdin_fix();
        }
    }
    ui.move_coefs.dx = vals[0];
    ui.move_coefs.dy = vals[1];
    ui.move_coefs.dz = vals[2];
}

static void get_scale_coefs(void)
{
    char tags[] = {'x', 'y', 'z'};
    double vals[3];
    for (size_t i = 0; i < 3; ++i)
    {
        while (1)
        {
            printf("Введите k%c: ", tags[i]);
            if (scanf("%lf", &vals[i]) == 1)
                break;
            else
                printf("Некорректно\n");
            stdin_fix();
        }
    }
    ui.scale_coefs.kx = vals[0];
    ui.scale_coefs.ky = vals[1];
    ui.scale_coefs.kz = vals[2];
}

static void get_rotate_coefs(void)
{
    char tags[] = {'x', 'y', 'z'};
    double vals[3];
    for (size_t i = 0; i < 3; ++i)
    {
        while (1)
        {
            printf("Введите a%c: ", tags[i]);
            if (scanf("%lf", &vals[i]) == 1)
                break;
            else
                printf("Некорректно\n");
            stdin_fix();
        }
    }
    ui.rotate_coefs.ax = vals[0];
    ui.rotate_coefs.ay = vals[1];
    ui.rotate_coefs.az = vals[2];
}

void run(SDL_Renderer *renderer)
{
    SDL_Event event;
    int quit = 0;
    draw_scene(renderer);
    while (!quit)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_m:
                        get_move_coefs();
                        move_obj(renderer);
                        break;
                    case SDLK_s:
                        get_scale_coefs();
                        get_center();
                        scale_obj(renderer);
                        break;
                    case SDLK_r:
                        get_rotate_coefs();
                        get_center();
                        rotate_obj(renderer);
                        break;
                    case SDLK_F5:
                        load_obj(renderer);
                        break;
                    default:
                        break;
                }
            }
        }
        
        draw_scene(renderer);
    }
}

void cleanup(SDL_Window *window, SDL_Renderer *renderer)
{
    task_t cur_task;
    cur_task.action = DESTROY;
    process_task(cur_task);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
