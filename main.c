/* Knapsack problem */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  printf("Le fichier %s a été compilé le %s a %s\n", __FILE__, __DATE__, __TIME__);
  int menu1, sortie=0, n=0;
  if (argc>1 && argv[1])
  {
    n = atof(argv[1]);
  }
  else
  {
    error("Utilisation : ./main <Nombre d'objets> !");
    exit(1);
  }
  while(sortie==0){
    puts("");
    puts("=== Menu ===");
    puts("1 - Voir les variables");
    puts("0 - Quitter");
    puts("\nEntrez votre choix : ");
    scanf("%d",&menu1);

    switch(menu1){
      case 1:
      printf("Nombre d'objets : %d\n", n);
      break;

      case 0:
      sortie=1;
      break;

      default:
        printf("Choix non reconnu\n");
        break;
    }
  }

  return EXIT_SUCCESS;
}
