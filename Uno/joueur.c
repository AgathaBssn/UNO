#include "joueur.h"

#include <stdio.h>

void ajouter_carte(struct joueur* j, struct carte c) {
    if (j->nb_cartes < 108  ) {
        j->main[j->nb_cartes++] = c;
    }
    else {
        printf("Erreur : main pleine pour %s\n", j->nom);
    }
}

void afficher_main(const struct joueur* j) {
    printf("Main de %s (%d cartes) :\n", j->nom, j->nb_cartes);
    for (int i = 0; i < j->nb_cartes; i++) {
        printf("[%d] ", i);
        afficher_carte(&j->main[i]);
    }
}

struct carte jouer_carte(struct joueur* j, int index) {
    struct carte c = { 0 }; //carte vide
    if (index < 0 || index >= j->nb_cartes) {
        printf("Index invalide pour la carte à jouer\n");
    }
    else {
        c = j->main[index];
        // Décale les cartes après index
        for (int i = index; i < j->nb_cartes - 1; i++) {
            j->main[i] = j->main[i + 1];
        }
        j->nb_cartes--;
    }
    return c;
}