#ifndef PLAYER_H
#define PLAYER_H

#include "../libs/eadk.h"
#include "types.h"
#include "graphics.h"
#include "bullet.h"

void updatePlayer(ship *player, camera *cam, eadk_keyboard_state_t keyboardState);


#endif