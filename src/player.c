#include "player.h"

const char *idle_sprite[] = {" o ", "/|\\", "/ \\"};
const char *walk_right_frame1[] = {" o ", "/|\\", "/ \\"};
const char *walk_right_frame2[] = {" o ", "/||", "> |"};
const char *walk_right_frame3[] = {" o ", "||\\", "| >"};

const char *walk_left_frame1[] = {" o ", "/|\\", "/ \\"};
const char *walk_left_frame2[] = {" o ", "|||", "< |"};
const char *walk_left_frame3[] = {" o ", "/|\\", "| <"};

void init_player(Player *p) {
  p->pos.x = 10;
  p->pos.y = 5;

  p->stats.will = 100;
  p->stats.san = 50;
  p->stats.max_will = 100;
  p->stats.max_san = 50;

  p->current_sprite = idle_sprite;
  p->walk_tick = 0;
}

void move_player(Player *p, int dx, int dy) {
  p->pos.x += dx;
  p->pos.y += dy;

  if (dx != 0 || dy != 0) {
    p->walk_tick++;
    if (p->walk_tick >= 6)
      p->walk_tick = 0;

    if (dx > 0) {
      if (p->walk_tick < 2) {
        p->current_sprite = walk_right_frame1;
      } else if (p->walk_tick < 4) {
        p->current_sprite = walk_right_frame2;
      } else {
        p->current_sprite = walk_right_frame3;
      }
    } else {
      if (p->walk_tick < 2) {
        p->current_sprite = walk_left_frame1;
      } else if (p->walk_tick < 4) {
        p->current_sprite = walk_left_frame2;
      } else {
        p->current_sprite = walk_left_frame3;
      }
    }
  } else {
    p->current_sprite = idle_sprite;
    p->walk_tick = 0;
  }
}
