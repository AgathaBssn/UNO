#pragma once

#include "paquet.h"


struct joueur {
    char nom[50];         // Nom du joueur (humain ou bot)
    struct carte main[NB_CARTES]; // Mains possible
    int nb_cartes;        // Nombre de cartes en main
    int est_bot;          // 1 si c’est le bot, 0 si humain
};

// Ajoute une carte à la main du joueur
void ajouter_carte(struct joueur* j, struct carte c);

// Affiche la main d’un joueur (utile pour humain)
void afficher_main(const struct joueur* j);

// Joue une carte de la main selon son index (retire la carte)
struct carte jouer_carte(struct joueur* j, int index);
