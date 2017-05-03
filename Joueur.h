/*!
\file Joueur.h
\brief Header de la classe Joueur
\author Kévin
\date 25 avril 2017
\version 1
*/

#pragma once
#include "Personnage.h"

/*! \class Joueur Joueur.h
    \brief classe Joueur
    Gère la création d'un personnage jouable ainsi que la gestion d'événement pouvant lui arriver
*/
class Joueur : public Personnage
{
public:
/*!
\brief Constructeur
	Initialise le joueur
\param string Le nom du fichier qui va être lu pour charger le joueur 
*/
	Joueur(std::string);
/*!
\brief Destructeur
	Automatiquement appelée a la destruction du joueur
*/
	~Joueur();
/*!
\brief Affiche la description des competences
*/
	void m_GetAllCompetence();
/*!
\brief Utilise une compétence
\param int le numéro de la competence a utiliser
\param Personnage* la cible de la competence
*/
	void m_UtiliserCompetence(int, Personnage*);
/*!
\brief Restaure automatiquement la vie du Joueur
*/
	void m_RestaurerSante();
/*!
\brief Restaure automatiquement le mana du Joueur
*/
	void m_RestaurerMana();
/*!
\brief Accesseur du nombre maximum de mana du joueur
*/
	int m_GetManaMax();
/*!
\brief Accesseur du nombre maximum de pv du joueur
*/
	int m_GetPVMax();

};

