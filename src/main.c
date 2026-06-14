#define _DEFAULT_SOURCE

#include "input.h"
#include "player.h"
#include "scene.h"
#include <unistd.h>

int main(void) {
  Player player;
  init_player(&player);

  char Screen[SCREEN_HEIGHT][SCREEN_WIDTH];

  create_game(Screen);

  init_input();

  while (1) {
    int key = get_key();
    switch (key) {
    case 'a':
      player.pos.x--;
      break;
    case 'd':
      player.pos.x++;
      break;
    case 'w':
      player.pos.y--;
      break;
    case 's':
      player.pos.y++;
      break;
    case 'q':
      cleanup_input();
      return 0;
    }
    render(Screen, &player);
    usleep(33333);
  }
}
