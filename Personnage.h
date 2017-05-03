/*!
\file Joueur.h
\brief Header de la classe Personnage
\author Kévin
\date 25 avril 2017
\version 1
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Competence.h"
#include "Interface.h"

class Competence;

/*! \class Personnage Personnage.h
    \brief classe Personnage
    Gère les principales caracteristique et actions de tout les personnages du jeu, monstre ou joueur
*/
class Personnage
{
protected:
	std::string nom; //!< Nom du personnage 
	int vitesse; //!< Vitesse en combat (désigne qui attaquera en premier)
	int manaMax; //!< Mana maximum
	int manaActuelle; //!< Le mana actuelle du personnage 
	int pvMax; //!< Le nombre de pv maximum du personnage
	int pvActuelle; //!< Les pv actuelle
	std::vector<Competence> competences; //!< Tableau regroupant les competences du personnage

/*!
\brief Utilise une competence
\param Competence* La competence a utiliser
\param Personnage* Le personnage Cible
*/
	void m_Utiliser(Competence*, Personnage*);

public:

/*!
\brief Constructeur de personnage
\param string Le nom du personnage a crée
*/
	Personnage(std::string);
/*!
\brief Destructeur de Personnage
*/
	~Personnage();

/*!
\brief Essaye d'utiliser une competence sur un personnage
\param int le numéro de la competence a utiliser
\param Personnage* la cible de la competence
*/
	void m_UtiliserCompetence(int,Personnage*);

/*!
\brief Accesseur du nombre de pv actuelle
\return le nombre de pv actuelle
*/
	int m_GetPV();

/*!
\brief accesseur du nombre de mana restant
\return le nombre de mana restant
*/
	int m_GetMana();
	
/*!
\brief Accesseur de la vitesse du personnage
\return la vitesse du personnage
*/
	int m_GetVitesse();
	
/*!
\brief Méthode utiliser pour faire perdre des points de vie a ce personnage
\param int le nombre de point de vie perdu (peut etre négatif pour regagner des pv)
*/
	void m_PrendreDegat(int);
	
/*!
\brief Méthode utiliser pour faire perdre des points de mana a ce personnage
\param int le nombre de points de mana perdu (peut etre négatif pour regagner du mana)
*/
	void m_PerdreMana(int);
	
/*!
\brief Renseigne le nombre de competence du personnage
\return le nombre de competence que le personnage connais
*/
	int m_GetNbrCompetence();
	
/*!
\brief Accesseur du nom du personnage
return string le nom du personnage
*/
	std::string m_GetNom();
};
