#include "player.h"

void init_player(Player *p) {
  p->pos.x = 10;
  p->pos.y = 5;

  p->stats.will = 100;
  p->stats.san = 50;
  p->stats.max_will = 100;
  p->stats.max_san = 50;
}

void move_player(Player *p, int dx, int dy) {
  p->pos.x += dx;
  p->pos.y += dy;
}
