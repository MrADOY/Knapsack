/* Knapsack problem */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "display.h"
#include "utils.h"
#include "glouglou.h"

int main(int argc, char const *argv[]) {
  printf("Le fichier %s a été compilé le %s à %s\n", __FILE__, __DATE__, __TIME__);
  srand(time(NULL));
  int sortie=0, n=0, poids=0, best_combinaison=0, total_poids_meilleur=0, total_cout_meilleur=0, total_poids=0, total_cout=0, dynamique=0, taille_sol = 0, n_old=0, borne_inf=0, borne_sup=0;
  char menu1;
  char menu2;
  int **tab = NULL;
  int *tab_2 = NULL;
  Object *tab_obj = NULL;
  if (argc>1 && argv[1]) {
    n = atof(argv[1]);
  }
  else {
    error("Utilisation : ./main <Nombre d'objets> !");
    exit(1);
  }
  while(sortie==0) {
    puts("");
    color(GREEN,"\t=== Menu ===");
    puts("1 - Générer les objets");
    if (tab_obj != NULL) {
      puts("2 - Voir les tableaux");
      puts("3 - Voir les variables");
    }
    if (n_old>n) {
      puts("4 - Remettre le nombre d'objets à sa valeur initiale");
    }
    puts("0 - Quitter");
    bold("\nEntrez votre choix : ");
    scanf(" %c",&menu1);
    puts("");
    switch(menu1) {
      case '1':
      color(YELLOW,"\t=== Génération ===");
      color(GREEN,"\t\t=== Menu de génération===");
      do{
        puts("\t1 - Générer les objets par énumération totale");
        puts("\t2 - Générer les objets par énumération intelligente");
        puts("\t3 - Générer les objets par dynamique dense");
        puts("\t4 - Générer les objets par glouton");
        puts("\t0 - Quitter");
        bold("\nEntrez votre choix : ");
        scanf(" %c", &menu2);

        switch(menu2){
          case '1':
          if (n>10) {
            color(BOLDRED,"\t=== Limitation à 10 objets dans ce mode ===");
            n_old=n;
            n=10;
          }
          tab = generate_combinaisons(n);
          tab_obj = generate_object_randomly(10,100,n);
          poids = generate_bag_capacity(tab_obj,n);
          best_combinaison = find_best_sum(tab,tab_obj,(1 << n)-1,poids);
          dynamique = 0;
          bold("\n\t\t=== Objets générés par énumération totale ===\n");
          menu2 = '0';
          break;

          case '2':
          if (n>10) {
            color(BOLDRED,"\t=== Limitation à 10 objets dans ce mode ===");
            n_old=n;
            n=10;
          }
          tab_obj = generate_object_randomly(10,100,n);
          poids = generate_bag_capacity(tab_obj,n);
          tab = generate_combinaisons_intelligente(n,tab_obj,poids);
          best_combinaison = find_best_sum(tab,tab_obj,(1 << n)-1,poids);
          break;

          case '3':
          if (n>5000) {
            color(BOLDRED,"\t=== Limitation à 5000 objets dans ce mode ===");
            n_old=n;
            n=5000;
          }
          tab_obj = generate_object_randomly(10,100,n);
          poids = generate_bag_capacity(tab_obj,n);
          tab = version_prog_dynamique(tab_obj,poids+1,n);
          tab_2 = find_solution(tab,n,poids,tab_obj,&taille_sol);
          dynamique=1;
          bold("\n\t\t=== Objets générés par dynamique dense===\n");
          menu2='0';
          break;

          case '4':
          tab_obj=generate_object_randomly(10,100,n);
          poids=generate_bag_capacity(tab_obj,n);
          tab_2=glouglou(tab_obj, n, poids, &borne_sup, &borne_inf);
          bold("\n\t\t=== Objets générés par glouton ===\n");
          menu2='0';
          break;

          case '0':
          break;

          default:
          error("Choix non reconnu !");
          break;
        }
      }while(menu2 != '0');

      color(BLUE,"\t=== Retour au menu principal ===");
      break;

      case '2':
      affiche_tab_obj(tab_obj, n);
      if (tab != NULL) {
        if (dynamique==0) {
          affiche_tab_total(tab, tab_obj, best_combinaison);
        }
        else {
          affiche_tab_dynamique(tab_2, tab_obj, taille_sol);
        }
      }
      else {
        affiche_tab_glouglou(tab_2, tab_obj);
      }
      color(BLUE,"\t=== Retour au menu ===");
      break;

      case '3':
      calcul_tab_obj(tab_obj, &total_poids, &total_cout, n);
      if (tab != NULL) {
        if (dynamique==0) {
          calcul_tab_total(tab, tab_obj, best_combinaison, &total_poids_meilleur, &total_cout_meilleur);
        }
        else {
          calcul_tab_dynamique(tab_2, tab_obj, &total_poids_meilleur, &total_cout_meilleur, taille_sol);
        }
      }
      else {
        calcul_tab_glouglou(tab_2, tab_obj, &total_poids_meilleur, &total_cout_meilleur);
      }
      affiche_var(n, poids, total_cout, total_poids, total_poids_meilleur, total_cout_meilleur, borne_inf, borne_sup);
      break;

      case '4':
      color(YELLOW,"\t=== Réinitialisation ===");
      tab = NULL;
      tab_2 = NULL;
      tab_obj = NULL;
      n=n_old;
      break;

      case '0':
      color(YELLOW,"\t=== Sortie ===");
      sortie=1;
      break;

      default:
      error("Choix non reconnu !");
      break;
    }
  }
  return EXIT_SUCCESS;
}
