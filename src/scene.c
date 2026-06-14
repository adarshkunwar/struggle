#include "scene.h"
#include "player.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

char grass_chars[] = {'.', ',', '`'};

char random_grass(int density) {
  int r = rand() % 100;
  if (r < density) {
    return grass_chars[rand() % 3];
  }
  return ' ';
}

void generate_sky(int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int density = 10;
      char c = random_grass(density);
      printf(GREY "%c" RESET, c);
    }
    printf("\n");
  }
}

void generate_grass(int width, int start_y, int height, Player *player) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {

      int world_y = start_y + y;

      int density = 100;
      char c = random_grass(density);

      if (player->pos.x == x && player->pos.y == world_y) {
        printf("@");
      } else {
        printf(GREEN "%c" RESET, c);
      }
    }
    printf("\n");
  }
}

int render(void) {

  Player player;

  init_player(&player);

  generate_sky(SCREEN_WIDTH, SCREEN_HEIGHT);
  generate_grass(SCREEN_WIDTH, SCREEN_HEIGHT / 3, SCREEN_HEIGHT * 2 / 3,
                 &player);

  printf("%d %d\n", player.pos.x, player.pos.y);
  return 1;
}
