#include "../libs/eadk.h"
#include "./graphics.h"

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "StarWorks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

typedef struct {
	int x, y, z;
} vertex;

typedef struct {
	int indexA, indexB;
} edge;

typedef struct {
	uint16_t nVertex, nEdges;
	vertex *vertices;
	edge *edges;
} model;

vertex cubeVertices[] = {
	{200, 200, 200}, {100, 200, 200}, 
	{200, 100, 200}, {200, 200, 100}, 
	{100, 100, 200}, {200, 100, 100}, 
	{100, 200, 100}, {100, 100, 100}
};

edge cubeEdges[] = {
	{0, 1}, {1, 4}, {4, 2}, {2, 0}
};

model cube = {
	8, 4,
	cubeVertices,
	cubeEdges
};

void drawModel2D(model m, eadk_color_t color) {
	// todo : add 3d
	for (int i = 0; i < m.nEdges; i++) {
		// get the indices of the two vertices connected by an edge
		int indexA = m.edges[i].indexA;
		int indexB = m.edges[i].indexB;

		vertex vertexA = m.vertices[indexA];
		vertex vertexB = m.vertices[indexB];
		drawLine(vertexA.x, vertexA.y, vertexB.x, vertexB.y, color);
	}
}

int main(int argc, char * argv[]) {
	eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);
	drawModel2D(cube, eadk_color_white);
	while(true) {
		eadk_keyboard_state_t keyboard = eadk_keyboard_scan();
		if (eadk_keyboard_key_down(keyboard, eadk_key_back)) {
			break;
		}
		eadk_timing_msleep(10);
	}
}
