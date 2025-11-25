
#include "uno.h"
#include "bot.h"
#include "joueur.h"
#include "paquet.h"
#include <stdio.h>
#include <string.h>

struct joueur joueurs[NB_JOUEURS];

void appliquer_effet_carte(struct carte c, int* joueur_courant, int nb_joueurs, int* sens_jeu) {
    if (strcmp(c.type, "PS") == 0) {
        // saute un tour
        *joueur_courant = (*joueur_courant + (*sens_jeu) + nb_joueurs) % nb_joueurs;
        printf("Joueur suivant sauté !\n");
    }
    else if (strcmp(c.type, "RV") == 0) {
        // changement de sens
        *sens_jeu = -(*sens_jeu);
        printf("Sens du jeu inversé !\n");
    }
    else if (strcmp(c.type, "+2") == 0) {
        // +2
        int joueur_suivant = (*joueur_courant + (*sens_jeu) + nb_joueurs) % nb_joueurs;
        for (int i = 0; i < 2; i++) {
            ajouter_carte(&joueurs[joueur_suivant], piocher());
        }
        *joueur_courant = joueur_suivant;
        printf("Joueur %d pioche 2 cartes et perd son tour !\n", joueur_suivant + 1);
    }
    else if (strcmp(c.type, "JJ") == 0) {
        // joker couleur
        printf("Choisissez la nouvelle couleur (0=ROUGE,1=JAUNE,2=BLEU,3=VERT) : ");
        int nouvelle_couleur;
        scanf("%d", &nouvelle_couleur);
        if (nouvelle_couleur >= 0 && nouvelle_couleur < NB_COULEURS) {
            talon[index_talon - 1].couleur = (enum couleurs)nouvelle_couleur;
        }
    }
    else if (strcmp(c.type, "+4") == 0) {
        // +4
        int joueur_suivant = (*joueur_courant + (*sens_jeu) + nb_joueurs) % nb_joueurs;
        for (int i = 0; i < 4; i++) {
            ajouter_carte(&joueurs[joueur_suivant], piocher());
        }
        *joueur_courant = joueur_suivant;
        printf("Joueur %d pioche 4 cartes et perd son tour !\n", joueur_suivant + 1);

        printf("Choisissez la nouvelle couleur (0=ROUGE,1=JAUNE,2=BLEU,3=VERT) : ");
        int nouvelle_couleur;
        scanf("%d", &nouvelle_couleur);
        if (nouvelle_couleur >= 0 && nouvelle_couleur < NB_COULEURS) {
            talon[index_talon - 1].couleur = (enum couleurs)nouvelle_couleur;
        }
    }
}

void initialiser_jeu() {
    creer_paquet();
    melanger_paquet();
    index_piocher = 0;
    index_talon = 0;

    strcpy(joueurs[0].nom, "Vous");
    joueurs[0].nb_cartes = 0;
    joueurs[0].est_bot = 0;

    strcpy(joueurs[1].nom, "Bot");
    joueurs[1].nb_cartes = 0;
    joueurs[1].est_bot = 1;

    for (int i = 0; i < 7; i++) {
        ajouter_carte(&joueurs[0], piocher());
        ajouter_carte(&joueurs[1], piocher());
    }

    talon[index_talon] = piocher();
    index_talon++;
}

void boucle_jeu() {
    int sens_jeu = 1;
    int joueur_courant = 0;

    while (1) {
        struct joueur* j = &joueurs[joueur_courant];
        struct carte carte_visible = talon[index_talon - 1];

        printf("\nTour de %s\n", j->nom);
        printf("Carte sur le talon : ");
        afficher_carte(&carte_visible);

        if (j->est_bot) {
            struct carte coup = jouer_coup_bot(j, carte_visible);
            if (coup.type[0] == 0) {
                // Bot pioche
                printf("Bot pioche une carte.\n");
                ajouter_carte(j, piocher());
            }
            else {
                ajouter_au_talon(coup);
                appliquer_effet_carte(coup, &joueur_courant, NB_JOUEURS, &sens_jeu);
            }
        }
        else {
            afficher_main(j);
            // TODO: Ajouter gestion saisie utilisateur pour jouer une carte ou piocher
            printf("Fonction saisie utilisateur non encore implémentée.\n");
        }

        if (j->nb_cartes == 0) {
            printf("%s a gagné la partie !\n", j->nom);
            break;
        }

        if (!j->est_bot) {
            // Passer au joueur suivant si humain n'a pas sauté/penalisé lui-même
            joueur_courant = (joueur_courant + sens_jeu + NB_JOUEURS) % NB_JOUEURS;
        }
    }
}
