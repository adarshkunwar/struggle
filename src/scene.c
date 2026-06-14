#define _DEFAULT_SOURCE

#include "scene.h"
#include "player.h"
#include "type.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define sky_density 20
#define grass_density 80

static char LastScreen[SCREEN_HEIGHT][SCREEN_WIDTH];
static int LastPlayerX = -1;
static int LastPlayerY = -1;
static int first_render = 1;

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
  if (first_render) {
    memset(LastScreen, 0xFF, sizeof(LastScreen));
    first_render = 0;
  }

  for (int i = 0; i < SCREEN_HEIGHT; i++) {
    for (int j = 0; j < SCREEN_WIDTH; j++) {
      int isPlayer = (player->pos.x == j && player->pos.y == i);
      int wasPlayer = (LastPlayerX == j && LastPlayerY == i);

      // skip if nothing changed
      if (!isPlayer && !wasPlayer && LastScreen[i][j] == Screen[i][j])
        continue;

      printf("\033[%d;%dH", i + 1, j + 1);
      if (isPlayer) {
        printf("@");
      } else if (i < SCREEN_HEIGHT / 3) {
        printf(GREY "%c" RESET, Screen[i][j]);
      } else {
        printf(GREEN "%c" RESET, Screen[i][j]);
      }

      LastScreen[i][j] = Screen[i][j];
    }
  }

  LastPlayerX = player->pos.x;
  LastPlayerY = player->pos.y;
  fflush(stdout);
  return 1;
}
