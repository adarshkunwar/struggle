#include "scene.h"
#include <stdio.h>

int main(void) {
  int test = render();
  if (!test) {
    printf("error");
  }
  return 0;
}
