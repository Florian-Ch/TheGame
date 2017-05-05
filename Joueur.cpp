#include "Joueur.h"

using namespace std;

Joueur::Joueur(string nomHeros) : Personnage(nomHeros)
{

}

Joueur::Joueur(string nomHeros, int pvAc,int manaAc) : Personnage(nomHeros)
{
	pvActuelle = pvAc;
	manaActuelle = manaAc;
}

Joueur::~Joueur()
{

}

void Joueur::m_UtiliserCompetence(int numeroCompetence, Personnage* cible)
{
	if (manaActuelle >= competences[numeroCompetence].m_getCoutMana())
	{
		manaActuelle -= competences[numeroCompetence].m_getCoutMana();
		m_Utiliser(&competences[numeroCompetence], cible);
	}
	else
		m_Utiliser(&competences[0], cible);
	
}

void Joueur::m_GetAllCompetence()
{
	for (int i = 0; i < competences.size(); i++){
		Interface::m_afficherLigne("[" + Interface::m_intTOstring(i+1) + "]" +competences[i].m_GetDescriptif());
	}
	
}

void Joueur::m_RestaurerSante()
{
	pvActuelle = pvMax;
}

void Joueur::m_RestaurerMana()
{
	manaActuelle = manaMax;
}

int Joueur::m_GetManaMax()
{
	return manaMax;
}

int Joueur::m_GetPVMax()
{
	return pvMax;
}
