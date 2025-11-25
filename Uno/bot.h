#pragma once
#ifndef BOT_H
#define BOT_H

#include "joueur.h"
#include "paquet.h"
#include "carte.h"

// bot plays
//  retourne la carte jouée ou une carte vide si le bot pioche
struct carte jouer_coup_bot(struct joueur* bot, struct carte carte_visible);

int carte_jouable(const struct carte* c, const struct carte* carte_visible);

#endif // BOT_H
