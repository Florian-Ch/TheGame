#include "Interface.h"

using namespace std;

Interface::Interface()
{
}


Interface::~Interface()
{
}

void Interface::m_afficherLigne(string phrase)
{
	cout << phrase<<endl;
}

void Interface::m_afficherChar(char lettre)
{
	cout << lettre;
}

int Interface::m_getIntegeur(int min, int max)
{
	string resultat;
	int res;
	bool boucle = true;
	do
	{
		cin >> resultat;
		res = Interface::m_stringTOint(resultat);
		if (res >= min && res <= max)
			boucle = false;
	} while (boucle);

	return res;
}

char Interface::m_getChar(char* possibilite, int tailleTableau)
{
	char resultat;
	bool boucle = true;
	do
	{
		cin >> resultat;
		for (int i = 0; i < tailleTableau; i++)
			if (resultat == possibilite[i])
				return resultat;
	} while (boucle);
}

void Interface::m_messageErreur(string message)
{
	cerr << message;
}

string Interface::m_getString()
{
	string resultat;
	cin >> resultat;
	return resultat;
}

int Interface::m_stringTOint(string leChiffre)
{
	istringstream buffer(leChiffre);
	int valeur;
	buffer >> valeur;
	return valeur;
}

string Interface::m_intTOstring(int leChiffre)
{
	stringstream ss;
	ss << leChiffre;
	return ss.str();
}
