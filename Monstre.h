/*!
\file Monstre.h
\brief Header de la classe Monstre
\author Kévin
\date 25 avril 2017
\version 1
*/

#pragma once
#include "Personnage.h"

/*! \class Monstre Monstre.h
    \brief classe Monstre
    Gère la création d'un monstre ainsi que la gestion d'événement pouvant lui arriver
*/
class Monstre : public Personnage
{
public:
/*!
\brief Constructeur
	Initialise le monstre
\param string Le nom du fichier qui va être lu pour charger le monstre 
*/
	Monstre(std::string);
/*!
\brief Destructeur
	Automatiquement appelée a la destruction du monstre
*/
	~Monstre();
/*!
\brief Utilise une compétence
\param int le numéro de la competence a utiliser
\param Personnage* la cible de la competence
*/
	void m_UtiliserCompetence(int, Personnage*);
};
