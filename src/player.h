#ifndef PLAYER_H
#define PLAYER_H

extern const char *idle_sprite[]; 
extern const char *walk_frame1[]; 
extern const char *walk_frame2[]; 
extern const char *walk_frame3[]; 

typedef struct {int x; int y;} Position;
typedef struct {int will; int san; int max_will; int max_san;} Stats;

typedef struct {
  Position pos;
  Stats stats;
  const char **current_sprite;
  int walk_tick;
} Player;


void init_player(Player *p);
void move_player(Player *p, int dx, int dy);


#endif // !PLAYER_H
