#pragma once
#ifndef CARTE_H
#define CARTE_H

#define NB_COULEURS 5 //penser à l'améliorer en utilisant la longueur de l'enum
#define NB_TYPE_COULEURS 3
#define NB_TYPE_NOIRES 2

enum couleurs { ROUGE, JAUNE, BLEU, VERT, NOIR };

extern enum couleurs couleurs[NB_COULEURS];
extern const char* types_couleurs[NB_TYPE_COULEURS];
extern const char* types_noires[NB_TYPE_NOIRES];

struct carte {
    enum couleurs couleur;
    char type[4];
};

void creer_carte(struct carte* c, enum couleurs couleur, const char* type);

#endif
