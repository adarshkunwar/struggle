#include "utils.h"
#include "type.h"
#include <stdlib.h>

char sample_terrain_char(char *option, int size, int density) {
  int r = rand() % 100;
  if (r < density) {
    return option[rand() % size];
  }
  return ' ';
}

int vary(int base, int variance) {
  int low = base - variance;
  int high = base + variance;

  return low + rand() % (high - low + 1);
}

Position position_generator() {

  int y = rand() % AVAILABLE_HEIGHT;
  int x = rand() % SCREEN_WIDTH;

  Position pos = {.x = x, .y = y};
  return pos;
};
