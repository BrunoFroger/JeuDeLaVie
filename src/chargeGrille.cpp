
#include <cstdio>
#include <stdlib.h>
#include <string>

#include "../inc/datas.hpp"
#include "../inc/afficheGrille.hpp"
#include "../inc/allocMemoireGrille.hpp"

int chargeGrille(char *nomGrille){
    FILE *fic = fopen(nomGrille,"r");
    char ligne[150];
    if (fic == NULL){
        printf("ERREUR => le fichier <%s> n'existe pas", nomGrille);
        return -1;
    } else{
        // printf("chargement de la grille prédéfine %s\n", nomGrille);
        strcpy(ligne, "");
        numPas=1;
        fgets(ligne, 100, fic);
        ligne[strlen(ligne)-1]='\0';
        char *pos = strchr(ligne, (int)'=');
        tailleGrille= atoi(pos+1);
        grille = allocMemoireGrille(grille);
        newGrille = allocMemoireGrille(newGrille);
        //printf("taille lue dans le fichier = <%d>\n", tailleGrille);
        //printf("chargement de %s de taille %d : <%20s>\n", nomGrille, tailleGrille, ligne);

        for (int i = 0 ; i < tailleGrille ; i++){
            char buffer[150];
            strcpy(buffer, "");
            strcpy(ligne, "");
            // fgets(ligne, tailleGrille+2, fic);
            if (fgets(ligne, 100, fic) == NULL) break;
            if (ligne == nullptr) continue;
            strcpy(buffer, ligne);
            buffer[strlen(buffer)-1]='\0';
            printf("chargement de la ligne %2d (taille %2d) : <%-20s> => <", i, (int)strlen(ligne), buffer);
            // printf("ligne %d lue = <%s>\n", i, ligne);
            for (int j = 0 ; j < tailleGrille ; j++){
                char car = '*';
                if ( j >= strlen(ligne)){
                    car = ' ';
                } else {
                    if (ligne[j] != '*') car = ' ';
                    //printf("grille[%d][%d]=<%c>\n", i, j, car);
                }
                printf("%c",car);
                grille[i][j] = car;
            }
            printf(">\n");
        }
        fclose (fic);
        //printf("fin de lecture du fichier %s\n", nomGrille);
    }
    //printf("fin fonction chargeGrille\n");
    //afficheGrille(grille);
    return 0;
}