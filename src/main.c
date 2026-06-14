#include "scene.h"
#include <stdio.h>

int main(void) {
  int test = create_field();
  if (!test) {
    printf("error");
  }
  return 0;
}
