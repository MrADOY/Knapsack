#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "display.h"

void error(char *message){
  fprintf(stderr, BOLDRED);
  fprintf(stderr, "#\n# ERREUR: %s\n#\n", message);
  fprintf(stderr, RESET);
}

void bold(char *message) {
  fprintf(stdout, BOLDWHITE);
  fprintf(stdout, "%s\n", message);
  fprintf(stdout, RESET);
}

void color(char *color, char *message) {
  fprintf(stdout, "%s", color);
  fprintf(stdout, "%s\n", message);
  fprintf(stdout, RESET);
}
