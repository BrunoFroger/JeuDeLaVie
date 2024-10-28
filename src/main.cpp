
#include <cstdio>
#include <string>
#include <cstdlib>

#include "../inc/datas.hpp"
#include "../inc/afficheGrille.hpp"
#include "../inc/chargeGrille.hpp"
#include "../inc/calculEvolution.hpp"
#include "../inc/analyseParametres.hpp"
#include "../inc/aide.hpp"

#define TAILLE_DEFAUT  10
char **grille;
char **newGrille;
char bidon [100];
char saisie[20]="";
char nomGrille[100]="";
int tailleGrille=TAILLE_DEFAUT;
bool noGrille=false;
bool modeAnime=false;
int delaiAnime=1;
int numPas=0;
int nbPas=1;
long int tmpNbPas;
int periode=0;

char *getOnOff(bool value){
    if (value){
        return (char *)"ON";
    } else {
        return (char *)"OFF";
    }
}

int main(int argc, char **argv){

    printf("Jeu de la vie\n");
    if (argc > 1){
        analyseParametres(argc, argv);
    }

    if (strlen(nomGrille) != 0) afficheGrille(grille);

    while (1){
        int fin = 0;
        strcpy(saisie, "");
        printf("Menu\n");
        printf("1 : charge grille (actuelle : %s ; periode : %d)\n", nomGrille, periode);
        printf("2 : affiche grille\n");
        printf("3 : evoluer de %d pas (%d)\n", nbPas, numPas);
        printf("4 : switch grille on/off (%s)\n", getOnOff(!noGrille));
        printf("5 : change nombre de pas a chaque iteration (%d)\n", nbPas);
        printf("6 : switch mode animation (%s) pour %d cycles (variable ci-dessus)\n", getOnOff(modeAnime), nbPas);
        printf("7 : delai entre pas animation (%d secondes)\n", delaiAnime);
        printf("a : aide\n");
        printf("l : liste des grilles disponibles\n");
        printf("q : quitter\n");
        printf("votre choix : ");
        scanf("%s", saisie);
        switch(saisie[0]){
            case '1' :  // charge grille
                strcpy(nomGrille, "");
                printf("Nom de la grille a charger : ");
                scanf("%s", nomGrille);
                chargeGrille(nomGrille);
                afficheGrille(grille);
                break;
            case '2' :  // affiche grille
                afficheGrille(grille);
                break;
            case '3' :  // Evolution de nbPas
                calculEvolution();
                afficheGrille(grille);
                break;
            case '4' : // switch on/off de la grille
                noGrille=!noGrille;
                afficheGrille(grille);
                break;
            case '5' :  // saisie nb pas 
                printf("Saisissez le nombre de pas a effectuer a chaque itération : ");
                scanf("%s", saisie);
                tmpNbPas=strtol(saisie, NULL, 10);
                if (tmpNbPas == 0){
                    printf("ERREUR : <%s> n'est pas un nombre valide\n", saisie);
                } else nbPas = (int)tmpNbPas;
                break;
            case '6' : // active mode animation
                modeAnime=!modeAnime;
                break;
            case '7' : // fixe delai entre chaque pas d'animation
                printf("Saisissez le delai entre chaque cycle d'animation : ");
                scanf("%s", saisie);
                tmpNbPas=strtol(saisie, NULL, 10);
                if (tmpNbPas == 0){
                    printf("ERREUR : <%s> n'est pas un nombre valide\n", saisie);
                } else delaiAnime = (int)tmpNbPas;
                break;
            case 'l' :
            case 'L' :
                printf("liste des ficheirs disponibles :\n");
                system("ls grilles/*");
                break;
            case 'a' :
            case 'A' :
            case '?' :
                aide();
                break;
            case 'q': // quitte le programme
            case 'Q':
                fin=1;
                break;
            default:
                printf("Commande <%s> inconnue\n", saisie);
        }
        if (fin) break;
    }
}