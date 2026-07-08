#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../libs/eadk.h"
#include <stdlib.h>
#include "types.h"
#include "constants.h"
#include <string.h>

extern uint8_t framebuffer[HEIGHT][WIDTH];

void drawPixel(int x, int y, uint8_t color);
void drawLine(int x0, int y0, int x1, int y1, uint8_t color);
void drawModel(const model *m, camera *cam, point3D pos, uint8_t color);
void flushFrameBuffer();

#endif