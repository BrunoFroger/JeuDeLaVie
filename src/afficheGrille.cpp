
#include <cstdio>

#include "../inc/datas.hpp"

void afficheLigneTableau(){
    for (int i = 0 ; i < tailleGrille ; i++){
        printf("+---");
    }
    printf("+\n");
}

void afficheGrille(char **tmpGrille){
    // printf("Affichage de la grille => debut\n");
    if(! noGrille) afficheLigneTableau();
    for (int i = 0 ; i < tailleGrille ; i++){
        for ( int j = 0 ; j < tailleGrille ; j++){
            char car = tmpGrille[i][j];
            if (car != '*') car = ' ';
            if(! noGrille) {
                printf("| %c ",car);
            } else {
                printf(" %c ",car);
            }
        }
        if(! noGrille){
            printf("|\n");
        } else {
            printf("\n");
        }
        if(! noGrille) afficheLigneTableau();
    }
    // printf("Affichage de la grille => fin\n");
}