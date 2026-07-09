#include "../libs/eadk.h"
#include "graphics.h"
#include "types.h"
#include "player.h"
#include "models.h"
#include "bullet.h"

/*
To do:
- complete line is erased if a part of it is behind us
- camera rotation
- enemies
- collisions
- hud
- stars
- menus
- delta time - not really important thanks to the wait_for_vblank() but still nice lol
*/

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "StarWorks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main() {

	camera playerCamera = {
		.position = {0, 50, 0}, 
		.rotation = {0, 0, 0}
	};

	ship player = {
		.shipModel = &arwing,
		.rotation = {0,50,0},
		.position = {0,0,100}
	};

	eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);

	initBullets();

	while(true) {
		eadk_keyboard_state_t keyboard = eadk_keyboard_scan();

		if (eadk_keyboard_key_down(keyboard, eadk_key_back)) {
			break;
		}

		updatePlayer(&player, &playerCamera, keyboard);
		updateBullets(&playerCamera);

		drawGround(&playerCamera);
		drawBullets(&playerCamera);
		drawModel(player.shipModel, &playerCamera, player.position, 2);
		
		
		eadk_display_wait_for_vblank();

		flushFrameBuffer();
	}
}
