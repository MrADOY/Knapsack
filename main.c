/* Knapsack problem */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "display.h"

int main(int argc, char const *argv[]) {
  printf("Le fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);
  int sortie=0, n=0;
  char menu1;
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
    puts("2 - Générer les objets");
    puts("0 - Quitter");
    puts("\nEntrez votre choix : ");
    scanf(" %c",&menu1);

    switch(menu1){
      case '1':
      puts("=== Variables ===");
      printf("Nombre d'objets : %d\n", n);


      break;

      case '2':
      puts("=== Génération ===");
      generate_object_randomly(0,100,n);
      break;

      case '0':
      puts("=== Sortie ===");
      sortie=1;
      break;

      default:
      error("Choix non reconnu !");
      break;
    }
  }

  return EXIT_SUCCESS;
}
