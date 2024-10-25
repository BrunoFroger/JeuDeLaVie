

#include <cstdio>
#include <cstdlib>

#include "../inc/datas.hpp"

char **allocMemoireGrille(char **tmpGrille){
    //printf("allocation de la memoire pour une grille\n");
    tmpGrille = (char **)malloc(sizeof(char*)*tailleGrille);
    for (int i = 0 ; i < tailleGrille ; i++){
        tmpGrille[i] = (char *)malloc(sizeof(char)*tailleGrille);
        for (int j = 0 ; j < tailleGrille ; j ++) tmpGrille[i][j] = ' ';
    }
    return tmpGrille;
}
