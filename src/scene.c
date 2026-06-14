#include "scene.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>

char grass_chars[] = {'.', ',', '`'};

char random_grass(int density) {
  int r = rand() % 100;

  if (r < density) {
    return grass_chars[rand() % 3];
  }
  return ' ';
}

void generate_grass(int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int density = (y * 100);
      char c = random_grass(density);
      printf(GREEN "%c" RESET, c);
    }
    printf("\n");
  }
}

int create_field(void) {

  // char path[50] = "assets/backgrounds/fields/ground.txt";
  //
  // FILE *f = fopen(path, "r");
  // if (!f) {
  //   perror("open assets/backgrounds/fields/ground.txt");
  //   return 0;
  // }

  // char line[SCREEN_WIDTH];
  // while (fgets(line, sizeof(line), f)) {
  //   line[strcspn(line, "\n")] = 0;
  //   printf(GREEN "%s" RESET "\n", line);
  //   fflush(stdout);
  // }

  generate_grass(SCREEN_WIDTH, SCREEN_HEIGHT);

  // fclose(f);
  return 1;
}
