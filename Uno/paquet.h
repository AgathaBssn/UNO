#pragma once
#ifndef PAQUET_H
#define PAQUET_H

#include "carte.h"

#define NB_CARTES 108
#define NB_TYPE_COULEURS 3
#define NB_TYPE_NOIRES 2
#define CARTES_PAR_JOUEUR 7

// tableu 4 couleurs
extern enum couleurs couleurs[NB_COULEURS];


extern struct carte paquet[NB_CARTES];
extern struct carte talon[NB_CARTES];

extern int index_piocher;  
extern int index_talon; 

// Fonction de création du paquet complet
void creer_paquet();

// Fonction de mélange
void melanger_paquet();

//1 si oui
int piocher_possible();

// Piocher une carte dans la pioche, carte null si vide
struct carte piocher();


void reconstituer_pioche();

// nb de cartes  dans la pioche
int cartes_restantes();

void ajouter_au_talon(struct carte c);


#endif // PAQUET_H
