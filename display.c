#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "display.h"

void error(char *message){
  fprintf(stderr, BOLDRED);
  fprintf(stderr, "#\n# ERREUR: %s\n#\n", message);
  fprintf(stderr, RESET);
}
