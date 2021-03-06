#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "data.h"
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

void affiche_tab_total(int **tab_combinaisons, Object *tab_obj, int best_combinaison) {
  int j=0;
  color(CYAN,"\t=== Objets dans le sac ===");
  printf(" ID | POIDS | PRIX\n");
  while (tab_combinaisons[best_combinaison][j] != -1) {
    printf("  %d |   %d  |  %d\n", tab_combinaisons[best_combinaison][j], tab_obj[tab_combinaisons[best_combinaison][j]].size, tab_obj[tab_combinaisons[best_combinaison][j]].cost);
    j++;
  }
}

void calcul_tab_total(int **tab_combinaisons, Object *tab_obj, int best_combinaison, int *total_poids_meilleur, int *total_cout_meilleur) {
  int j=0;
  *total_poids_meilleur=0;
  *total_cout_meilleur=0;
  while (tab_combinaisons[best_combinaison][j] != -1) {
    *total_poids_meilleur+=tab_obj[tab_combinaisons[best_combinaison][j]].size;
    *total_cout_meilleur+=tab_obj[tab_combinaisons[best_combinaison][j]].cost;
    j++;
  }
}

void affiche_tab_obj(Object *tab_obj, int nb_objets_total) {
  int i=0;
  color(CYAN,"\t=== Objets ===");
  printf(" ID | POIDS | PRIX\n");
  while (i < nb_objets_total) {
    printf("  %d |   %d  |  %d\n", i, tab_obj[i].size, tab_obj[i].cost);
    i++;
  }
}

void calcul_tab_obj(Object *tab_obj, int *total_poids, int *total_cout, int nb_objets_total) {
  int i=0;
  *total_poids=0;
  *total_cout=0;
  while (i < nb_objets_total) {
    *total_poids+=tab_obj[i].size;
    *total_cout+=tab_obj[i].cost;
    i++;
  }
}

void affiche_tab_dynamique(int *tab, Object *tab_obj, int taille_sol) {
  color(CYAN,"\t=== Objets dans le sac ===");
  printf(" ID | POIDS | PRIX\n");
  for (int i = 0; i < taille_sol; i++) {
    printf("  %d |   %d  |  %d\n", tab[i], tab_obj[tab[i]].size, tab_obj[tab[i]].cost);
  }
}

void calcul_tab_dynamique(int *tab, Object *tab_obj, int *total_poids_meilleur, int *total_cout_meilleur, int taille_sol) {
  *total_poids_meilleur=0;
  *total_cout_meilleur=0;
  for (int i = 0; i < taille_sol; i++) {
    *total_poids_meilleur+=tab_obj[tab[i]].size;
    *total_cout_meilleur+=tab_obj[tab[i]].cost;
  }
}

void affiche_tab_glouglou(int *tab, Object *tab_obj) {
  color(CYAN,"\t=== Objets dans le sac ===");
  printf(" ID | POIDS | PRIX\n");
  int i=0;
  while(tab[i]!=-1) {
    printf("  %d |   %d  |  %d\n", tab[i], tab_obj[tab[i]].size, tab_obj[tab[i]].cost);
    i++;
  }
}

void calcul_tab_glouglou(int *tab, Object *tab_obj, int *total_poids_meilleur, int *total_cout_meilleur) {
  *total_poids_meilleur=0;
  *total_cout_meilleur=0;
  int i=0;
  while(tab[i]!=-1) {
    *total_poids_meilleur+=tab_obj[tab[i]].size;
    *total_cout_meilleur+=tab_obj[tab[i]].cost;
    i++;
  }
}

void affiche_var(int n, int poids, int total_cout, int total_poids, int total_poids_meilleur, int total_cout_meilleur, int borne_inf, int borne_sup) {
  color(YELLOW, "\t=== Variables ===");
  if ( borne_sup!=0) {
    printf("\tBorne inférieure : %d\n", borne_inf);
    printf("\tBorne supérieure : %d\n", borne_sup);
  }
  color(CYAN,"\t\t=== Objets ===");
  printf("\tNombre total d'objets : %d\n", n);
  if (total_cout>0) {
    printf("\tPoids total des objets : %d kg\n", total_poids);
    printf("\tCoût total des objets : %d €\n", total_cout);
  }
  if (total_poids_meilleur>0) {
    color(CYAN,"\t\t=== Sac ===");
    if (poids>0) {
      printf("\tCapacité du sac : %d kg\n", poids);
      printf("\tCapacité restant dans le sac : %d kg\n", poids-total_poids_meilleur);
    }
    printf("\tPoids total des objets dans le sac : %d kg\n",  total_poids_meilleur);
    printf("\tCoût total des objets dans le sac : %d €\n", total_cout_meilleur);
  }
  if (total_poids_meilleur>0) {
    color(CYAN,"\t\t=== Reste ===");
    if (poids>0) {
      printf("\tCapacité restant à prendre : %d kg\n", total_poids-total_poids_meilleur);
      printf("\tPerte : %d €\n", total_cout-total_cout_meilleur);
    }
  }
  color(BLUE,"\t=== Retour au menu ===");
}
