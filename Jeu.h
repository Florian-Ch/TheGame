#pragma once
/*!
\file Jeu.h
\brief Header de la classe Jeu
\author Florian
\date 22 avril 2017
\version 1
*/

#include "Map.h"
#include "Joueur.h"
#include "Combat.h"
#include "Interface.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>


/*! \class Jeux Jeu.h
    \brief classe Jeux

    Gère le fonctionnement du jeu en général
*/
class Jeux{
private:	
	/*!
		\enum Etat
		\brief états possibles du jeu
     	*/
	enum Etat {
		e_Initialisation,	/*!< Phase d'initialisation*/
		e_Exploration,		/*!< Phase de déplacement sur la map*/
		e_Combat,		/*!< Phase de combat*/
		e_FinDuJeu		/*!< Phase de fin de partie*/
	};
	Etat etatJeux;	//!< Etat actuel du jeu
	Joueur* heros;	//!< Héros incarné par le joueur
	int difficulty;	//!< Difficulté du jeu
	Map carte;	//!< Map qui sera utilisée pour la partie
	bool end;	//!< Détecte la fin du jeu
public:
/*!
\brief Constructeur
	Passe l'état du jeu à Initialisation
	Initialise la fin à false
*/
	Jeux();
/*!
\brief Permet au joueur de choisir son héros parmi ceux créés par le client
*/
	void m_getJoueur();
/*!
\brief Permet au joueur de choisir la difficulté
*/
	void m_selectDifficulty();
/*!
\brief Choisi la map de façon aléatoire parmi celles de la difficulté donnée
*/
	void m_getMap();
/*!
\brief Actualise les phases de jeu
*/
	void m_update();
/*!
\brief Fonction pour transmettre au main.cpp la fin du jeu
\return vrai ou faux pour terminer la partie dans le main
*/
	bool m_getEtat();
/*!
\brief Destructeur
*/
	~Jeux();
};
