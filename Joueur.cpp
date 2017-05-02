#include "Joueur.h"

using namespace std;

Joueur::Joueur(string nomHeros) : Personnage(nomHeros)
{

}


Joueur::~Joueur()
{

}

void Joueur::m_UtiliserCompetence(int numeroCompetence, Personnage* cible)
{
	if (manaActuelle > competences[numeroCompetence].m_getCoutMana())
	{
		manaActuelle -= competences[numeroCompetence].m_getCoutMana();
		m_Utiliser(&competences[numeroCompetence], cible);
	}
	else
		m_Utiliser(&competences[0], cible);
	
}

vector<string>* Joueur::m_GetAllCompetence()
{
	vector<string>* resultat;
	for (int i = 0; i < competences.size(); i++){
cout<<competences[i].m_GetDescriptif()<<endl;
//		resultat->push_back(competences[i].m_GetDescriptif());
	}
	return resultat;
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
