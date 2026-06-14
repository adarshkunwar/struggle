#include "scene.h"
#include "type.h"
#include <stdio.h>
#include <string.h>

int create_field(void) {

  char path[50] = "assets/backgrounds/fields/ground.txt";

  FILE *f = fopen(path, "r");
  if (!f) {
    perror("open assets/backgrounds/fields/ground.txt");
    return 0;
  }

  char line[50];
  while (fgets(line, sizeof(line), f)) {
    line[strcspn(line, "\n")] = 0;
    printf(GREEN "%s" RESET "\n", line);
    fflush(stdout);
  }

  fclose(f);
  return 1;
}
