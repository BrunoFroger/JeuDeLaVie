# JeuDeLaVie

Ce programme simule le fameux jeu de la vie

Au lancement le programme s'execute en mode intéractif avec affichage du menu suivant :
Menu
1 : charge grille (actuelle :  ; periode : 0)
2 : affiche grille
3 : evoluer de 1 pas (0)
4 : switch grille on/off (ON)
5 : change nombre de pas a chaque iteration (1)
6 : switch mode animation (OFF) pour 1 cycles (variable ci-dessus)
7 : delai entre pas animation (10 secondes)
a : aide
l : liste des grilles disponibles
q : quitter
votre choix : 

Par ailleur au lancement vous avez la possibilité de lui passer des paramètres conformement a la description ci-dessous :

    jeuDeLaVie [options] fichierGrille [options]
        fichierGrille : nom du fichier contenant la grille a charger
        options :
            --no-grille : pas d'affichage de la grille entourant les cellules
            --anim      : activation du mode animation

