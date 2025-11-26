#include "paquet.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carte paquet[NB_CARTES];    // Le paquet de 108 cartes
struct carte talon[NB_CARTES];     // Le talon (défausse)
int index_talon = 0;               // Nombre de cartes dans le talon
int index_piocher = 0;

void creer_paquet() {
    int nb_carte_creee = 0;
    for (int idx = 0; idx < NB_COULEURS-1; idx++) {
        enum couleurs couleur = couleurs[idx];
        //  1 à 9 en deux fois
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= 9; i++) {
                struct carte c;
                char type[3];
                snprintf(type, sizeof(type), "%d", i);
                creer_carte(&c, couleur, type);
                paquet[nb_carte_creee++] = c;
            }
        }
        //  0 une fois
        struct carte c;
        char type[3];
        snprintf(type, sizeof(type), "%d", 0);
        creer_carte(&c, couleur, type);
        paquet[nb_carte_creee++] = c;

        // RV SK +2 *2
        for (int t = 0; t < 3; t++) {
            for (int n = 0; n < 2; n++) {
                struct carte c;
                creer_carte(&c, couleur, types_couleurs[t]);
                paquet[nb_carte_creee++] = c;
            }
        }
    }
    // noires JJ et +4
    for (int t = 0; t < 2; t++) {
        for (int n = 0; n < 4; n++) {
            struct carte c;
            creer_carte(&c, NOIR, types_noires[t]);
            paquet[nb_carte_creee++] = c;
        }
    }
}


void melanger_paquet() {
    /*init random*/
    srand(time(NULL));
    for (int i = NB_CARTES - 1; i > 0; i--) { //faire une variable globale
        int j = rand() % (i + 1); //al
        struct carte temp = paquet[i];
        paquet[i] = paquet[j];
        paquet[j] = temp;
    }
}
#define CARTES_PAR_JOUEUR 7

struct joueur {
    struct carte main[NB_CARTES];  // taille max au cas où
    int nb_cartes;
};

int cartes_restantes() {
    return NB_CARTES - index_piocher;
}

int piocher_possible() {
    return cartes_restantes() > 0;
}

struct carte piocher() {
    if (!piocher_possible()) {
        reconstituer_pioche();
        if (!piocher_possible()) {
            struct carte vide = { 0 };
            return vide; // plus de cartes du tout
        }
    }
    return paquet[index_piocher++];
}


void reconstituer_pioche() {
    if (index_piocher >= NB_CARTES) {  // pioche vide
        if (index_talon <= 1) {
            // plus de carte dans la pioche, gerer le cas
            return;
        }
        // garde al derniere
        struct carte derniere_carte = talon[index_talon - 1];

        // recuperer dans pioche
        int nb_a_reconstituer = index_talon - 1;
        for (int i = 0; i < nb_a_reconstituer; i++) {
            paquet[i] = talon[i];
        }

        // remelanger
        index_piocher = 0;
        index_talon = 1;
        talon[0] = derniere_carte;  // garder la dernière carte dans le talon

        // Mélanger la nouvelle pioche reconstituée
        melanger_paquet();
    }
}


void ajouter_au_talon(struct carte c) {
    if (index_talon < NB_CARTES) {
        talon[index_talon++] = c;
    }
    else {
        printf("tableau talon dépassé   \n");
    }
}

