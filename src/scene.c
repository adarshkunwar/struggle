#define _DEFAULT_SOURCE

#include "scene.h"
#include "player.h"
#include "type.h"
#include "utils.h"
#include <stdio.h>
#include <unistd.h>

#define sky_density 20
#define grass_density 80

char character_options[] = {'.', ',', '`'};

int create_game(char Screen[SCREEN_HEIGHT][SCREEN_WIDTH]) {

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      if (i < SCREEN_HEIGHT / 3) {
        char character = sample_terrain_char(character_options, 3, sky_density);
        Screen[i][j] = character;
      } else {
        char character =
            sample_terrain_char(character_options, 3, grass_density);
        Screen[i][j] = character;
      }
    }
  }

  return 1;
}

int render(char Screen[SCREEN_HEIGHT][SCREEN_WIDTH], Player *player) {
  // No while loop here — just draw one frame and return
  printf("\033[2H");
  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      printf("\033[%d;%dH", i + 1, j + 1); // move to exact row, col
      if (player->pos.x == j && player->pos.y == i) {
        printf("@");
      } else if (i < SCREEN_HEIGHT / 3) {
        printf(GREY "%c" RESET, Screen[i][j]);
      } else {
        printf(GREEN "%c" RESET, Screen[i][j]);
      }
    }
  }
  fflush(stdout);
  fflush(stdout);
  return 1;
}
