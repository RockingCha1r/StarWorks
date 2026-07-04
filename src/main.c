#include "../libs/eadk.h"
#include "graphics.h"
#include "camera.h"
#include "types.h"

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "StarWorks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

const int focalDistance = 100;

point3D cubeVertices[] = {
	{50, 50, 50}, {-50, 50, 50}, 
	{50, -50, 50}, {50, 50, -50}, 
	{-50, -50, 50}, {50, -50, -50}, 
	{-50, 50, -50}, {-50, -50, -50}
};

edge cubeEdges[] = {
	{0,1}, {1,4},
	{4,2}, {2,0},


	{3,6}, {6,7},
	{7,5}, {5,3},


	{0,3}, {1,6}, 
	{2,5}, {4,7}   
};

model cube = {
8, 12,
	cubeVertices,
	cubeEdges
};

void drawModel(model m, camera cam, point3D pos, eadk_color_t color) {

	int finalCoordinates[m.nVertex][2]; // will contain the final coordinates to draw
	
	for (int i = 0; i < m.nVertex; i++) {
		int posX = pos.x + m.vertices[i].x - cam.position.x;
		int posY = pos.y + m.vertices[i].y - cam.position.y;
		int posZ = pos.z + m.vertices[i].z - cam.position.z;

		finalCoordinates[i][0] = (posX * focalDistance) / posZ + 160;
		finalCoordinates[i][1] = - (posY * focalDistance) / posZ + 111;
	}

	for (int i = 0; i < m.nEdges; i++) {
		// get the indices of the two vertices connected by an edge
		int indexA = m.edges[i].indexA;
		int indexB = m.edges[i].indexB;

		drawLine(finalCoordinates[indexA][0], finalCoordinates[indexA][1], finalCoordinates[indexB][0], finalCoordinates[indexB][1], color);
	}
}

int main(int argc, char * argv[]) {

	camera playerCamera = {
		.position = {0, 0, 0}, 
		.rotation = {0, 0, 0}
	};

	while(true) {
		eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);


		eadk_keyboard_state_t keyboard = eadk_keyboard_scan();
		if (eadk_keyboard_key_down(keyboard, eadk_key_back)) {
			break;
		}

		if (eadk_keyboard_key_down(keyboard, eadk_key_up)) {
			playerCamera.position.z += 1;
		}

		if (eadk_keyboard_key_down(keyboard, eadk_key_down)) {
			playerCamera.position.z -= 1;
		}

		if (eadk_keyboard_key_down(keyboard, eadk_key_left)) {
			playerCamera.position.x -= 1;
		}

		if (eadk_keyboard_key_down(keyboard, eadk_key_right)) {
			playerCamera.position.x += 1;
		}

		drawModel(cube, playerCamera, (point3D){0, 0, 100}, eadk_color_white);
		eadk_timing_msleep(10);
	}
}
