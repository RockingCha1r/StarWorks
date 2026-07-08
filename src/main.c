#include "../libs/eadk.h"
#include "graphics.h"
#include "types.h"
#include "player.h"
#include "models.h"

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

	ship player = {
		.shipModel = &arwing,
		.rotation = {0,0,0},
		.position = {0,0,100}
	};

	eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);

	while(true) {
		eadk_keyboard_state_t keyboard = eadk_keyboard_scan();

		if (eadk_keyboard_key_down(keyboard, eadk_key_back)) {
			break;
		}

		updatePlayer(&player, &playerCamera, keyboard);

		eadk_display_wait_for_vblank();

		flushFrameBuffer();
	}
}
