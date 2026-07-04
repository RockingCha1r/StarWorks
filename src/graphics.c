
#include "graphics.h"

void draw_pixel(int x, int y, eadk_color_t color) {
	eadk_rect_t pixelRect = {
		x, y, 1, 1
	};
	eadk_display_push_rect(pixelRect, &color);
}

void draw_line(int x0, int y0, int x1, int y1, eadk_color_t color) {
	// to do: put the result in a buffer
	int deltaX = abs(x1 - x0);
	int deltaY = abs(y1 - y0);
	int parameter;
	int stepX = (x0 < x1) ? 1 : -1;
	int stepY = (y0 < y1) ? 1 : -1;
	int currentX = x0;
	int currentY = y0;
	draw_pixel(currentX, currentY, color);
	if (deltaX >= deltaY) {
		parameter = 2 * deltaY - deltaX;
		for (int i = 0; i < deltaX; i++) {
			currentX+= stepX;
			if (parameter >= 0) {
				currentY+= stepY;
				parameter += (deltaY << 1) - (deltaX << 1);
			} else {
				parameter += (deltaY << 1);
			}
			draw_pixel(currentX, currentY, color); 
		}
	} else {
		parameter = 2 * deltaX - deltaY;
		for (int i = 0; i < deltaY; i++) {
			currentY+= stepY;
			if (parameter >= 0) {
				currentX+= stepX;
				parameter += (deltaX << 1) - (deltaY << 1);
			} else {
				parameter += (deltaX << 1);
			}
			draw_pixel(currentX, currentY, color); 
		}
	}
}