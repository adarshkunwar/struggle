#ifndef ENEMY_H
#define ENEMY_H

#include "type.h"
typedef struct { int will; int max_will;} Stats;

typedef enum {
  ENEMY_SKELETON = 0,
  ENEMY_GHOST,
  ENEMY_TYPE_COUNT,
} EnemyType;

typedef struct {
  Position pos;
  Stats stats;
  const char **current_sprite;
  const char **frames[3];
  int walk_tick;
  EnemyType type;
  const char *name;
} Enemy;

typedef struct {
  const char *name;
  int base_will;
  int will_variance;
  const char **idle;
  const char **frames[3];
} EnemyTemplate;

int fight(void);
Enemy create_enemy(EnemyType type);
void animate(Enemy *e);

#endif
