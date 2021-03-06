/**
* \file		vue_plateau.c
* \brief	Contient le code source du module vue_plateau
* \author	Tendry
* \date		29 Novembre 2014
*/

// ######################
// INCLUSIONS
#include <stdio.h>
#include <stdlib.h>
#include <vue_plateau.h>
#include <position.h>
// ######################

void affiche_plateau(Plateau* plateau)
{
	// Variables de parcours
	int i = 0, j = 0;

	for(i = 0; i < plateau->matrice.nbLignes; i++)
	{
		for(j = 0; j < plateau->matrice.nbColonnes; j++)
		{
			Position position = position_init(i, j);
			affiche_case(plateau, &position);
		}
		printf("\n");
	}
}

void affiche_case(Plateau* plateau, Position* position)
{
	// On récupère le contenu 
	Pion pion = plateau_getpion(plateau, *position);

	// S'il y a un pion à la position
	if(pion.identifiant != -1)
	{
		char affiche[2];

		// On adapte la taille de ce qui sera affiché
		if(pion.identifiant < 10)
			sprintf(affiche , "0%d", pion.identifiant);
		else
			sprintf(affiche, "%d", pion.identifiant);

		// On adapte la couleur !!
		char couleur[10];

		switch(pion.couleur)
		{
			case ROUGE:
				sprintf(couleur,"%s", "\033[31m");
				break;

			case BLEU:
				sprintf(couleur,"%s", "\033[34m");
				break;

			case VERT:
				sprintf(couleur,"%s", "\033[32m");
				break;

			case JAUNE:
				sprintf(couleur,"%s", "\033[33m");
				break;

			default:
				break;		
		}

		// On affiche la couleur
		printf("%s", couleur);

		// Puis le pion
		printf("[%s]", affiche);
	}
	else
	{
		// On affiche rien
		printf("\033[37m[  ]");
	}

	// On remet la couleur par défaut
	printf("\033[0m");
}
