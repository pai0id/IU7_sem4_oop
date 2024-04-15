#include "UI.h"

int main(void)
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    err_t rc = init(&window, &renderer);
    if (rc)
        print_err_msg(rc);

    run(renderer);
    cleanup(window, renderer);
    return 0;
}
