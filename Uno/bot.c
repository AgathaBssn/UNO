#include "bot.h"
#include "carte.h"
#include "joueur.h"
#include "paquet.h"
#include <stdio.h>
#include <string.h>

//  vérifie si une carte est jouable sur une carte donnée
 int carte_jouable(const struct carte* c, const struct carte* carte_visible) {
    // Au UNO, carte jouable si même couleur ou même type
    return (
        c->couleur == carte_visible->couleur) //mm couleur
        || (strcmp(c->type, carte_visible->type) == 0) //mm chiffre ou special
        || (c->couleur == NOIR); //noir toujours
}

// Le bot joue la 1ere carte qu il peut jouer
struct carte jouer_coup_bot(struct joueur* bot, struct carte carte_visible) {
    for (int i = 0; i < bot->nb_cartes; i++) {
        if (carte_jouable(&bot->main[i], &carte_visible)) {
            struct carte carte_a_jouer = bot->main[i];
            // decaler la main du bot
            for (int j = i; j < bot->nb_cartes - 1; j++) {
                bot->main[j] = bot->main[j + 1];
            }
            bot->nb_cartes--;
            printf("%s joue : ", bot->nom);
            afficher_carte(&carte_a_jouer);
            return carte_a_jouer;
        }
    }
    // Pas de carte jouable, bot doit piocher (retourne carte vide)
    struct carte vide = { 0 };
    printf("%s doit piocher\n", bot->nom);
    return vide;
}
