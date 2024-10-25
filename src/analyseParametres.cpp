


#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "../inc/datas.hpp"
#include "../inc/aide.hpp"
#include "../inc/chargeGrille.hpp"

void analyseParametres(int nb, char**params){
    char param[100];
    bool paramOK = false;
    if (nb == 1 ) return;
    for (int i = 1 ; i < nb ; i ++){
        strcpy(param, params[i]);
        // printf("analyse du parametre %d (%s)\n", i, param);
        if (param[0] != '-') {
            strcpy(nomGrille, param);
            int res = chargeGrille(nomGrille);
            if (res != 0){
                aide();
                exit(-1);
            }
            paramOK=true;
        }
        if (strcmp(param, "--no-grille") == 0) {
            noGrille=true;
            paramOK=true;
        }
        if (strcmp(param, "--anim") == 0) {
            modeAnime=true;
            paramOK=true;
        }
        if (! paramOK) {
            printf("ERREUR => parametre <%s> inconnu \n", param);
            aide();
            exit (-1);
        }
    }

}