#include "../libs/eadk.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "StarWorks";
const uint32_t eadk_api_level  __attribute__((section(".rodata.eadk_api_level"))) = 0;

int main(int argc, char * argv[]) {
	eadk_display_push_rect_uniform(eadk_screen_rect, eadk_color_black);
	while(true) {
		eadk_keyboard_state_t keyboard = eadk_keyboard_scan();
		if (eadk_keyboard_key_down(keyboard, eadk_key_back)) {
			break;
		}
	}
}
