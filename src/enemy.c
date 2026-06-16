#include "enemy.h"
#include "type.h"
#include "utils.h"

static const char *skeleton_idle[] = {" o ", "/|\\", "/ \\"};
static const char *skeleton_frame1[] = {" o ", "/|\\", "/ \\"};
static const char *skeleton_frame2[] = {" o ", "-|-", "/ \\"};
static const char *skeleton_frame3[] = {" o ", "\\|/", "/ \\"};

static const char *ghost_idle[] = {"(o)", " | ", "~~~"};
static const char *ghost_frame1[] = {"(o)", "~|~", " ~~"};
static const char *ghost_frame2[] = {"(o)", " | ", "~~~"};
static const char *ghost_frame3[] = {"(o)", "~|~", "~~ "};

static const EnemyTemplate templates[ENEMY_TYPE_COUNT] = {
    [ENEMY_SKELETON] = {.name = "skeleton",
                        .base_will = 20,
                        .will_variance = 2,
                        .idle = skeleton_idle,
                        .frames = {skeleton_frame1, skeleton_frame2,
                                   skeleton_frame3}},
    [ENEMY_GHOST] = {.name = "ghost",
                     .base_will = 20,
                     .will_variance = 2,
                     .idle = ghost_idle,
                     .frames = {ghost_frame1, ghost_frame2, ghost_frame3}},
};

Enemy create_enemy(EnemyType type) {
  const EnemyTemplate *t = &templates[type];
  Enemy e;

  Position pos = position_generator();
  int will = vary(t->base_will, t->will_variance);

  e.pos.x = pos.x;
  e.pos.y = pos.y;
  e.type = type;
  e.name = t->name;
  e.stats.will = will;
  e.stats.max_will = will;
  e.current_sprite = t->idle;
  e.walk_tick = 0;
  e.frames[0] = t->frames[0];
  e.frames[1] = t->frames[2];
  e.frames[2] = t->frames[2];
  return e;
}

void animate(Enemy *e) {
  if (e->walk_tick > 15) {
    e->walk_tick = 0;
  }
  e->walk_tick++;

  if (e->walk_tick < 5) {
    e->current_sprite = e->frames[0];
  } else if (e->walk_tick < 10) {
    e->current_sprite = e->frames[1];
  } else {
    e->current_sprite = e->frames[2];
  }
}
