#include "paquet.h"
#include <string.h>
#include <stdio.h>


void creer_paquet() {
	int nb_carte_creee = 0;
	for (int idx = 0; idx < NB_COULEURS; idx++) {
		{
			enum couleurs couleur = couleurs[idx];
			/*ajouter 2 de chaque valeur de 1 à 9*/
			for (int j = 1; j <= 2; j++) {
				for (int i = 1; i <= 9; i++) {
					struct carte c;
					char type[3];
					snprintf(type, sizeof(type), "%d", i); // convertir i en chaine
					creer_carte(&c, couleur, type); //remplir la carte
					paquet[nb_carte_creee++] = c;   // ajouter au paquet
				}
			}
			/*Ajouter un 0 de chaque couleur*/
			struct carte c;
			char type[3];
			snprintf(type, sizeof(type), "%d", 0); // valeur 0
			creer_carte(&c, couleur, type); //remplir la carte
			paquet[nb_carte_creee++] = c;   // ajouter au paquet
		
			/*Ajouter 2 cartes spéciales de chaque couleur*/
			for (int t = 0; t < 3; t++) { // pour chaque type spécial RV,  PS, +2
				for (int n = 0; n < 2; n++) { // 2 exemplaires de chaque
					struct carte c;
					creer_carte(&c, couleur, types_couleurs[t]);
					paquet[nb_carte_creee++] = c;
				}
			}

			/*Ajouter 4 de chaque cartes Noires */
			for (int t = 0; t < 2; t++) { // pour chaque type spécial JJ, +4
				for (int n = 0; n < 4; n++) { 
					struct carte c;
					creer_carte(&c, NOIR, types_noires[t]);
					paquet[nb_carte_creee++] = c;
				}
			}
		}
	}
}