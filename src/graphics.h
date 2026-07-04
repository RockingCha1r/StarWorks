#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../libs/eadk.h"
#include <stdlib.h>

void draw_pixel(int x, int y, eadk_color_t color);
void draw_line(int x0, int y0, int x1, int y1, eadk_color_t color);

#endif