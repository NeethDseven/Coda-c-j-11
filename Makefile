# Nom de l'exécutable
EXEC = Sokoban

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g

# Fichiers objets (générés à partir des fichiers .c)
OBJ = main.o display.o interaction.o

# Règle par défaut : créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

# Règle pour compiler main.c en main.o
main.o: main.c  display.h
	$(CC) $(CFLAGS) -c main.c


# Règle pour compiler display.c en display.o
display.o: display.c display.h
	$(CC) $(CFLAGS) -c display.c

display.o: interaction.h interaction.c
	$(CC) $(CFLAGS) -c interaction.c

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour nettoyer uniquement les fichiers objets
cleanobj:
	rm -f $(OBJ)