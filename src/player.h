#ifndef PLAYER_H
#define PLAYER_H

typedef struct {int x; int y;} Position;
typedef struct {int will; int san; int max_will; int max_san;} Stats;

typedef struct {
  Position pos;
  Stats stats;
} Player;


void init_player(Player *p);
void move_player(Player *p, int dx, int dy);


#endif // !PLAYER_H
