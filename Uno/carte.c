enum couleurs { ROUGE, JAUNE, BLEU, VERT, NOIR };


struct carte {
	enum couleurs couleur;
	char type[3];  // "+2", "+4", "JJ", "RV", "PS" ou chiffre comme "0"-"9"
};

