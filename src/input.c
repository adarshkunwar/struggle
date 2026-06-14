#include "input.h"

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

static struct termios oldt;

void init_input(void) {
  struct termios newt;

  tcgetattr(STDIN_FILENO, &oldt);

  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);

  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void cleanup_input(void) { tcsetattr(STDIN_FILENO, TCSANOW, &oldt); }

int get_key(void) {
  char c;

  if (read(STDIN_FILENO, &c, 1) > 0)
    return c;

  return -1;
}
