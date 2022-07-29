#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int verif(char* tab, int nbre);
int vi(char *tab, char l, int nbre);

int main()
{

	char motSecret[] = "MONTAGNE";
	char *motTrouve = NULL;
	char lettrep = 'p';
	int i = 0, nbre = 0, vies = 10;
	int* v = &vies;

	for (i = 0; motSecret[i] != '\0'; i++) {
		nbre++;
	}

	motTrouve = malloc(nbre * sizeof(*motTrouve));

	for (i = 0; i < nbre; i++)
		motTrouve[i] = '*';

	printf("Bienvenue dans le jeu du pendu.\n");

	do {
		printf("\nIl vous reste %d vies, veuillez proposez une lettre -> ", *v);
		scanf("%c", &lettrep);
		lettrep = toupper(lettrep);
		while (getchar() != '\n');

		for (i = 0; i < nbre; i++) {
			if (lettrep == motSecret[i] && motTrouve[i] == '*')
				motTrouve[i] = lettrep;
		}

		*v = *v + vi(motSecret, lettrep, nbre);
;		printf("Le mot mystere est -> ");

		for (i = 0; i < nbre; i++) {
			if (i == nbre - 1)
				printf("%c\n", motTrouve[i]);
			else
				printf("%c", motTrouve[i]);
		}
	} while (verif(motTrouve, nbre) && *v > 0);
	if (*v > 0)
		printf("\nFelicitation vous avez trouve le mot mystere!\n");
	else
		printf("\nDommage, vous avez perdu toutes vos vies.\n");
	free(motTrouve);
	return 0;
}

int verif(char* tab, int nbre) { //verif si une lettre n'a pas été encore trouvé.
	for (int i = 0; i < nbre; i++) {
		if (tab[i] == '*')
			return 1;
	}
	return 0;
}

int vi(char *tab, char l, int nbre) { //fonction pour enlever vies.

	for (int i = 0; i < nbre; i++) {
		if (tab[i] == l)
			return 0;
	}
	return -1;
}