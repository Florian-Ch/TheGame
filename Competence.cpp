#include "Competence.h"

using namespace std;

/*

Nom de la compétence
Coût mana
Dégâts
Mana retiré à la cible
PV rendus au lanceur
Mana rendu au lanceur

*/

Competence::Competence(string nom)
{
	string nomFichier = "Competence/" + nom + ".txt";
	string nf = "";
	for(int i=0; i<50; i++)
		if((int)nomFichier[i] > 30)
			nf+= nomFichier[i];
	ifstream fichier(nf.c_str());

	if (fichier)
	{
		string res;
		getline(fichier, res);
		this->nom = res;
		getline(fichier, res);
		coutMana = Interface::m_stringTOint(res);
		getline(fichier, res);
		degat = Interface::m_stringTOint(res);
		getline(fichier, res);
		ManaRetirerCible = Interface::m_stringTOint(res);
		getline(fichier, res);
		soinLanceur = Interface::m_stringTOint(res);
		getline(fichier, res);
		ManaRenduLanceur = Interface::m_stringTOint(res);
	}
	else
		Interface::m_messageErreur(nomFichier + " : Fichier non trouvé");
}

Competence::~Competence()
{

}

int Competence::m_getCoutMana()
{
	return coutMana;
}

string Competence::m_GetDescriptif()
{
	string res = nom + ": ";
	if (coutMana != 0)
		res += "Cout en mana [" + Interface::m_intTOstring(coutMana) + "] ";
	if (degat != 0)
		res += "Degat [" + Interface::m_intTOstring(degat) + "] ";
	if (ManaRenduLanceur != 0)
		res += "Rend [" + Interface::m_intTOstring(ManaRenduLanceur) + "] de mana ";;
	if (ManaRetirerCible != 0)
		res += "Retire [" + Interface::m_intTOstring(ManaRetirerCible) + "] mana a la cible ";
	if (soinLanceur != 0)
		res += "Vous soigne de " + Interface::m_intTOstring(soinLanceur) + "] ";
	return res;
}

int Competence::m_getDegat()
{
	return degat;
}

int Competence::m_getManaRetirer()
{
	return ManaRetirerCible;
}

int Competence::m_getSoinLanceur()
{
	return soinLanceur;
}

int Competence::m_getManaRenduLanceur()
{
	return ManaRenduLanceur;
}
