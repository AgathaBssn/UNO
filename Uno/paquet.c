#include "paquet.h"
#include <string.h>
#include <stdio.h>


void creer_paquet() {
	int nb_carte_creee = 0;
	for (int idx = 0; idx < NB_COULEURS; idx++) {
		{
			enum couleurs couleur = couleurs[idx];
			/*ajouter 4 de chaque valeur de 1 à 9*/
			for (int j = 1; j <= 4; j++) {
				for (int i = 1; i <= 9; i++) {
					struct carte c;
					char type[3];
					snprintf(type, sizeof(type), "%d", i); // convertir i en chaine
					creer_carte(&c, couleur, type); // remplir la carte
					paquet[nb_carte_creee++] = c;   // ajouter au paquet
				}
			}
			/*Ajouter un 0*/
		}
	}
}