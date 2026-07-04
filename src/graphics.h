#ifndef GRAPHICS_H
#define GRAPHICS_H

#define CENTER_X 160
#define CENTER_Y 120

#include "../libs/eadk.h"
#include <stdlib.h>
#include "types.h"
#include "camera.h"
#include "constants.h"

void drawPixel(int x, int y, eadk_color_t color);
void drawLine(int x0, int y0, int x1, int y1, eadk_color_t color);
void drawModel(model m, camera cam, point3D pos, eadk_color_t color);

#endif