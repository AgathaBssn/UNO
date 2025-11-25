#ifndef UNO_H
#define UNO_H

#include "joueur.h"

#define NB_JOUEURS 2

extern struct joueur joueurs[NB_JOUEURS];

// Initialise le jeu : paquet, joueurs, distribution, talon
void initialiser_jeu();

// Boucle principale du jeu UNO (gestion des tours)
void boucle_jeu();


void appliquer_effet_carte(struct carte c, int* joueur_courant, int nb_joueurs, int* sens_jeu);
#endif // UNO_H
