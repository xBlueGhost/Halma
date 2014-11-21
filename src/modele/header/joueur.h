/**
 * \file      joueur.h
 * \author    Quentin
 * \version   1.0
 * \date      21 novembre 2014
 * \brief     Définit d'un joueur
 *
 * \details   Définit la structure d'un joueur par un ensemble de pions
 */
 
#ifndef JOUEUR_H
#define JOUEUR_H

 //######################################
//Inclusions
#include "pion.h"
//######################################

 /**
* \brief Un joueur est un ensemble de pions
* \auhtor Quentin
* \version 1.0
*/

typedef struct Joueur Joueur;

 struct Joueur{

 	/**
	* \brief Le nombre de pions que le joueur a
	*/
 	int nombrePions; //Nombre total de pions necessaires ( 9 ou 15 selon le mode de jeu)

 	/**
	* \brief Un pion
	* /see Pion
	*/
 	Pion pion;
 };

  #endif
