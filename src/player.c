#include "player.h"

void updatePlayer(ship *player, camera *cam, eadk_keyboard_state_t keyboardState) {

    if (eadk_keyboard_key_down(keyboardState, eadk_key_up)) {
        cam->position.z += 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_down)) {
        cam->position.z -= 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_left)) {
        cam->position.x -= 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_right)) {
        cam->position.x += 1;
    }

    drawModel(player->shipModel, cam, (point3D){0, 0, 100}, 1);
}