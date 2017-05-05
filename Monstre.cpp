#include "Monstre.h"

using namespace std;

Monstre::Monstre(string nom) : Personnage("Monstre/" + nom + ".txt")
{
}


Monstre::~Monstre()
{
}

void Monstre::m_setMana(int mana)
{
	manaActuelle = mana;
}

void Monstre::m_UtiliserCompetence(int numeroCompetence, Personnage* cible)
{
	if (manaActuelle >= competences[numeroCompetence].m_getCoutMana())
	{
		manaActuelle -= competences[numeroCompetence].m_getCoutMana();
		m_Utiliser(&competences[numeroCompetence], cible);
		Interface::m_afficherLigne(nom + " vous attaque avec " + competences[numeroCompetence].m_GetNom()+ " et vous fait [" + Interface::m_intTOstring(competences[numeroCompetence].m_getDegat()) + "] degats");
		Interface::m_afficherLigne("");
	}
	else
	{
		for (int i = 0; i < competences.size(); i++)
		{
			if (manaActuelle >= competences[i].m_getCoutMana())
			{
				manaActuelle -= competences[i].m_getCoutMana();
				m_Utiliser(&competences[i], cible);
				Interface::m_afficherLigne(nom + " vous attaque avec " + competences[i].m_GetNom() + " et vous fait [" + Interface::m_intTOstring(competences[i].m_getDegat()) + "] degats");
				Interface::m_afficherLigne("");
				break;
			}
		}
	}
}

void Monstre::m_UtiliserCompetenceSA(int numeroCompetence, Personnage* cible)
{
	if (manaActuelle >= competences[numeroCompetence].m_getCoutMana())
	{
		manaActuelle -= competences[numeroCompetence].m_getCoutMana();
		m_Utiliser(&competences[numeroCompetence], cible);
	}
	else
	{
		for (int i = 0; i < competences.size(); i++)
		{
			if (manaActuelle >= competences[i].m_getCoutMana())
			{
				manaActuelle -= competences[i].m_getCoutMana();
				m_Utiliser(&competences[i], cible);
				break;
			}
		}
	}
}
