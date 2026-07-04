#include "../libs/eadk.h"
#include "graphics.h"
#include "camera.h"
#include "types.h"
#include "models.h"

#define WIDTH 280
#define HEIGHT 200

/*
To do:
- watch out for division by zero in drawmodel
- objects behind us are visible
- buffer for Bresenham
- camera rotation
- NumWorks screen height/width
- delta time
*/

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "StarWorks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

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
