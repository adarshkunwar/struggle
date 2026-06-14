#include "type.h"
#define _POSIX_C_SOURCE 200809L
#define _DEFAULT_SOURCE
#include "input.h"
#include "player.h"
#include "scene.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int sig) {
  (void)sig;
  cleanup_input();
  exit(0);
}

int main(void) {
  Player player;
  init_player(&player);
  char Screen[SCREEN_HEIGHT][SCREEN_WIDTH];
  create_game(Screen);
  init_input();
  signal(SIGINT, handle_sigint);
  while (1) {
    int key = get_key();
    switch (key) {
    case 'a':
      if (player.pos.x > 0)
        player.pos.x--;
      break;
    case 'd':
      if (player.pos.x < SCREEN_WIDTH - 1)
        player.pos.x++;
      break;
    case 'w':
      if (player.pos.y > SCREEN_HEIGHT - GROUND_HEIGHT + 1)
        player.pos.y--;
      break;
    case 's':
      if (player.pos.y < SCREEN_HEIGHT - 1)
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
