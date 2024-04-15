#include "draw.h"

void draw_line(const scene_t &scene, const point_t &p1, const point_t &p2)
{
    int x1 = (int)(p1.x + scene.width / 2);
    int y1 = (int)(-p1.y + scene.height / 2);
    int x2 = (int)(p2.x + scene.width / 2);
    int y2 = (int)(-p2.y + scene.height / 2);
    set_color_canvas(scene.renderer, scene.draw_color);  // Done
    draw_line_canvas(scene.renderer, x1, y1, x2, y2);
}

void clear(const scene_t &scene)
{
    set_color_canvas(scene.renderer, scene.bg_color);  // Done
    clear_canvas(scene.renderer);
}
