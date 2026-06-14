#include "scene.h"
#include <stdio.h>

int create_field(void) {

  char path[50] = "assets/backgrounds/fields/ground.txt";

  FILE *f = fopen(path, "r");
  if (!f) {
    perror("open assets/backgrounds/fields/ground.txt");
    return 0;
  }

  char line[50];
  while (fgets(line, sizeof(line), f)) {
    printf("%s", line);
  }

  fclose(f);
  return 1;
}
