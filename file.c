#include <stdio.h>
#include <stdlib.h>

int read_file(char* path){
  char* line = NULL;
  int len = 0;
  int read = 0;
  FILE *fp;
  fp = fopen(path, "w+");
  while ((read = gets(1024,&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);
  }
}
