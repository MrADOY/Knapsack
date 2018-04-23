#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "data.h"

/*
  Save random values in file path
*/
void  save_file(char *path, Object* tab, int size){

  FILE *fd = NULL;
  if ((fd = fopen(path, "w")) == NULL){
    perror("fail open file");
    exit(-1);
  }
  fprintf(fd, "%d\n", size);
  for (int i = 0; i < size; i++) {
      fprintf(fd, "%d;%d\n",tab[i].size, tab[i].cost);
  }
}

/*
  Load values for file path in t
*/
int load_file(char *path, Object *t){

  char str[128];
  char *ptr;
  FILE *fd = NULL;
  if ((fd = fopen(path, "r")) == NULL){
    perror("fail open file");
    exit(-1);
  }
  ptr = fgets(str, 128, fd);
  int nb = atoi(ptr);
  t = (Object*)malloc(nb * sizeof(Object));
  for (int i = 0; i < nb; i++) {
    ptr = fgets(str, 128, fd);
    t[i].size = atoi(strsep(&ptr, ";"));
    t[i].cost = atoi(strsep(&ptr, ";"));
  }
  return nb;
}
