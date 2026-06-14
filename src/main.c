#include "player.h"
#include "scene.h"
#include "type.h"
#include <stdio.h>

int main(void) {

  Player player;
  init_player(&player);

  char Screen[SCREEN_HEIGHT][SCREEN_WIDTH];

  if (create_game(Screen) != 1) {
    perror("game couldn't be created");
  }
  int test = render(Screen);
  if (!test) {
    printf("error");
  }
  return 0;
}
