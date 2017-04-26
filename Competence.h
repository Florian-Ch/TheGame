#pragma once
#include <fstream>
#include "Interface.h"

class Competence
{
	/*
	Nom de la comp�tence
	Co�t mana
	D�g�ts
	Mana retir� � la cible
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
	int m_getCoutMana();
	int m_getDegat();
	int m_getManaRetirer();
	int m_getSoinLanceur();
	int m_getManaRenduLanceur();
	std::string m_GetDescriptif();
	
};

