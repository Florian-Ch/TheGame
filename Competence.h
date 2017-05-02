#pragma once
#include <fstream>
#include "Interface.h"

class Competence
{
	/*
	Nom de la compétence
	Coût mana
	Dégâts
	Mana retiré à la cible
	PV rendus au lanceur
	Mana rendu au lanceur
	*/
private:
	std::string nom;
	int coutMana;
	int degat;
	int ManaRetirerCible;
	int soinLanceur;
	int ManaRenduLanceur;
public:
	Competence(std::string);
	~Competence();
	std::string m_GetNom();
	int m_getCoutMana();
	int m_getDegat();
	int m_getManaRetirer();
	int m_getSoinLanceur();
	int m_getManaRenduLanceur();
	std::string m_GetDescriptif();
	
};

