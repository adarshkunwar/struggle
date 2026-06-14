#include "utils.h"
#include <stdlib.h>

char sample_terrain_char(char *option, int size, int density) {
  int r = rand() % 100;
  if (r < density) {
    return option[rand() % size];
  }
  return ' ';
}
