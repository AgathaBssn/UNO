# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Recherche automatique de tous les .c dans le dossier courant
SRCS = $(wildcard *.c)

# Transformation de la liste des sources en objets
OBJS = $(SRCS:.c=.o)

# Nom de l'exécutable final
EXEC = uno

# Règle par défaut
all: $(EXEC)

# Lien de l'exécutable avec tous les objets
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compilation des .c en .o (si tu as des headers, considérer les dépendances manuellement si besoin)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer
clean:
	rm -f $(OBJS) $(EXEC)
