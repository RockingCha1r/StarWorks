#include "player.h"

void updatePlayer(ship *player, camera *cam, eadk_keyboard_state_t keyboardState) {
    //ok it looks bad rn because we're moving the ship and not the camera, but that's normal, trust me guys

    if (eadk_keyboard_key_down(keyboardState, eadk_key_up)) {
        player->position.y += 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_down)) {
        player->position.y -= 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_left)) {
        player->position.x -= 1;
    }

    if (eadk_keyboard_key_down(keyboardState, eadk_key_right)) {
        player->position.x += 1;
    }

    cam->position.z += CAMERA_SPEED;
    player->position.z = cam->position.z + 80;

    if (player->position.x > cam->position.x + 50) { player->position.x = cam->position.x + 50;} 
    if (player->position.x < cam->position.x - 50) { player->position.x = cam->position.x - 50;} 
    if (player->position.y > cam->position.y + 50) { player->position.y = cam->position.y + 50;} 
    if (player->position.y < cam->position.y - 50) { player->position.y = cam->position.y - 50;} 
    
    

    drawModel(player->shipModel, cam, player->position, 2);
}