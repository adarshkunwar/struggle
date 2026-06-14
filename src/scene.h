#ifndef SCENE_H
#define SCENE_H

#include "player.h"
#include "type.h"
int render(char Screen[SCREEN_HEIGHT][SCREEN_WIDTH], Player *player);
int create_game(char Screen[SCREEN_HEIGHT][SCREEN_WIDTH] );

#endif // !SCENE_H
