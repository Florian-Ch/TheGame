/**
  \file Combat.cpp
  \brief Classe Combat
  \author Thomas
  \details Attributs et Méthodes de la classe Combat
 
 
 
 */


/*!	\class Combat
 	\brief classe Combat	

	Fonctionement du Combat
*/
#pragma once
#include "Monstre.h"
#include "Joueur.h"
#include "Personnage.h"
#include <cstdlib>
#include <string>
#include "Interface.h"


class Combat
{

	private:
	
	Joueur* heros;		/*!< Héros du joueur*/
	Monstre monstre;	/*!< Monstre à combattre*/ 	
	bool fin_cbt;		/*!< Etat du combat*/ 	

	public:
	
	/*!
	\fn public Combat(Joueur*,Monstre)
	\brief Fonction qui construit le combat
	*/
	Combat(Joueur*,std::string);
	
	/*!
	\fn public m_CombatLancement()
	\brief Fonction qui gere le deroulement du combat
	*/
	void m_CombatLancement();
	
	/*!
	\fn public m_Affichage()
	\brief Fonction qui gere l'affichage du combat
	*/	
	void m_Affichage();
	
	/*!
	\fn public m_ChoixCompHeros()
	\brief Fonction qui gere le choix de comp du heros
	*/
	void m_ChoixCompHeros();
	
	/*!
	\fn public m_ChoixCompMonstre()
	\brief Fonction qui gere le choix de comp du monstre
	*/
	void m_ChoixCompMonstre();
	
	
};

