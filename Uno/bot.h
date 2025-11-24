#pragma once
#ifndef BOT_H
#define BOT_H

#include "joueur.h"
#include "paquet.h"
#include "carte.h"

// Fonction du bot pour jouer son tour
// Elle retourne la carte jouée (ou une carte vide si le bot pioche)
// paramètres : le joueur bot, la carte face visible sur le talon
struct carte jouer_coup_bot(struct joueur* bot, struct carte carte_visible);

#endif // BOT_H
