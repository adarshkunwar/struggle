#include "enemy.h"

const char *idle_sprite_enemy[] = {" o ", "/|\\", "/ \\"};
const char *animation_frame_1[] = {" o ", "/|\\", "/ \\"};
const char *animation_frame_2[] = {" o ", "/|\\", "/ \\"};
const char *animation_frame_3[] = {" o ", "/|\\", "/ \\"};

void create_enemy(Enemy *e) {
  e->pos.x = 10;
  e->pos.y = 5;

  e->stats.will = 100;
  e->stats.san = 50;
  e->stats.max_will = 100;
  e->stats.max_san = 50;

  e->current_sprite = idle_sprite_enemy;
  e->walk_tick = 0;
}

void animate(Enemy *e) {
  if (e->walk_tick > 15) {
    e->walk_tick = 0;
  }
  e->walk_tick++;

  if (e->walk_tick < 5) {
    e->current_sprite = animation_frame_1;
  } else if (e->walk_tick < 10) {
    e->current_sprite = animation_frame_2;
  } else {
    e->current_sprite = animation_frame_3;
  }
}
