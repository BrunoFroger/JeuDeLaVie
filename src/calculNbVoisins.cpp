

#include <cstdio>

#include "../inc/datas.hpp"

int valCellule(int i,int j){
    if (i < 0) return 0;
    if (i >= tailleGrille) return 0;
    if (j < 0) return 0;
    if (j >= tailleGrille) return 0;
    if (grille[i][j] == '*') return 1;
    return 0;
}

int calculNbVoisins(int i, int j){
    //printf("calcul nb voisin de %d, %d : ", i, j);
    int nbVoisins = 0;

    nbVoisins += valCellule(i-1,j-1);
    nbVoisins += valCellule(i-1,j);
    nbVoisins += valCellule(i-1,j+1);
    nbVoisins += valCellule(i,j-1);
    nbVoisins += valCellule(i,j+1);
    nbVoisins += valCellule(i+1,j-1);
    nbVoisins += valCellule(i+1,j);
    nbVoisins += valCellule(i+1,j+1);

    //printf(" %d ", nbVoisins);
    //if (j == tailleGrille - 1) printf("\n");
    return nbVoisins;
}