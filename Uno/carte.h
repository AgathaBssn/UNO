#pragma once
#ifndef CARTE_H
#define CARTE_H

#define NB_COULEURS 4 //penser à l'améliorer en utilisant la longueur de l'enum
enum couleurs { ROUGE, JAUNE, BLEU, VERT };

extern enum couleurs couleurs[NB_COULEURS];
extern const char* types[];



struct carte {
    enum couleurs couleur;
    char type[3];
};

void creer_carte(struct carte* c, enum couleurs couleur, const char* type);

#endif
