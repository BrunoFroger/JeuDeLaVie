

#include <cstdio>
#include <unistd.h>

#include "../inc/datas.hpp"
#include "../inc/calculNbVoisins.hpp"
#include "../inc/afficheGrille.hpp"


void calculEvolution(void){
    int tmpNbPas=nbPas;
    while (tmpNbPas > 0){
    // printf("Execution d'un pas d'évolution");
        for (int i = 0 ; i < tailleGrille ; i++){
            for (int j = 0 ; j < tailleGrille ; j++){
                newGrille[i][j]=' ';
                //printf("analyse de %d,%d=<%c> => ", i, j, grille[i][j]);
                int nbVoisins = calculNbVoisins(i,j);
                if (grille[i][j] == ' '){
                    // cellule morte
                    if (nbVoisins == 3){
                        newGrille[i][j] = '*';
                        //printf("naissance en %d,%d => ", i, j);
                    } 
                } else {
                    // cellule vivante
                    if ((nbVoisins == 2) || (nbVoisins == 3)){
                        newGrille[i][j] = '*';
                        //printf("vie conservee en %d,%d => ", i, j);
                    } else {
                        // mort de la cellule
                        newGrille[i][j]=' ';
                    }
                }
                //printf(" %c\n", newGrille[i][j]);
            }
        }
        //afficheGrille(newGrille);
        for (int i = 0 ; i < tailleGrille ; i++){
            for (int j = 0 ; j < tailleGrille ; j++){
                grille[i][j]=newGrille[i][j];
            }
        }
        if (modeAnime){
            if (tmpNbPas > 0){
                afficheGrille(grille);
                sleep(delaiAnime);
            } else {
                modeAnime=!modeAnime;
            }
        }
        // afficheGrille(grille);
        numPas++;
        tmpNbPas--;
    }
}