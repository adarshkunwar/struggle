#ifndef ENEMY_H
#define ENEMY_H

extern const char *idle_sprite_enemy[];
extern const char *animation_frame_1[];
extern const char *animation_frame_2[];
extern const char *animation_frame_3[];

typedef struct { int x; int y; } Position;
typedef struct { int will; int san; int max_will; int max_san; } Stats;

typedef struct {
  Position pos;
  Stats stats;
  const char **current_sprite;
  int walk_tick;
} Enemy;

int fight(void);
void create_enemy(Enemy *e);
void animate(Enemy *e);

#endif
