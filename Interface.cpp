#include "Interface.h"

using namespace std;

Interface::Interface()
{
}


Interface::~Interface()
{
}

void Interface::m_afficherLigne(string phrase)
	cout << phrase << endl;
}

void Interface::m_afficherChar(char lettre)
	cout << lettre;
}

int Interface::m_getIntegeur(int min, int max)
{
	int resultat;
	bool boucle = true;
	do
	{
		cin >> resultat;
		if (resultat > min && resultat < max)
			boucle = false;
	} while (boucle);

	return resultat;
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

//permet la converion d'un int en string
string Interface::m_intToString(int i){		
	ostringstream oss;
	oss<<i;
	return oss.str();
}
