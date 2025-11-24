#include "carte.h"
#include <string.h>

/* attention les types doivent faire que 2 char*/
enum couleurs couleurs[NB_COULEURS] = { ROUGE, JAUNE, BLEU, VERT, NOIR };
const char* types_couleurs[NB_TYPE_COULEURS] = { "RV", "PS", "+2" };
const char* types_noires[NB_TYPE_NOIRES] = { "JJ", "+4" };



void creer_carte(struct carte* c, enum couleurs couleur, const char* type) {
    //récupère la couleur
    c->couleur = couleur;
    //prend la taille du type
    strncpy(c->type, type, sizeof(c->type) - 1);
    //complète avec \0
    c->type[sizeof(c->type) - 1] = '\0';
}
