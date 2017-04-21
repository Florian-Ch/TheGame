#include "Combat.h"
#include <cstdlib>
#include <string>
#include "Interface.h"

using namespace std;

Combat::Combat(Joueur* h,Monstre m)
{
	heros=h;
	monstre=m;
	fin_cbt=false;
}

void Combat::m_ChoixCompHeros()							//Méthode qui permet au joueur de choisir une compétence a utiliser
{
	
	m_afficherLigne("C'est a votre tour, quelle compétence voulez vous utiliser ?"); 	
	
	int n = Interface::m_getInteger(0, heros->m_GetNbCompetence());								
	heros->m_UtiliserCompetence(n,&monstre);					
}

void Combat::m_ChoixCompMonstre()						//Méthode qui définit l'IA du monstre à améliorer
{

	int nbc=monstre.m_GetNbCompetence();					//Recup le nbr de comp du monstre
	int m=rand()%nbc;							//Genre un nombre aléatoire pour savoir qu'elle comp utiliser
	monstre.m_UtiliserCompetence(m,heros);
	m_afficherLigne("Le monstre vient de jouer");				
}

void Combat::m_Affichage()
{
	system("clear");
	m_afficherLigne(heros->m_GetNom()+":");
	m_afficherLigne("Pv:"+heros->m_GetPV());
	m_afficherLigne("Mana:"+heros->m_GetMana());
	m_afficherLigne(heros->m_GetAllCompetence());

	m_afficherLigne(monstre.m_GetNom()+":");
	m_afficherLigne("Pv:"+monstre.m_GetPV());
	m_afficherLigne("Mana:"+monstre.m_GetMana());
}

void Combat::m_CombatLancement()
{

	m_Affichage();

	while(fin_cbt==false)
	{
		if(heros->m_GetVitesse()>monstre.m_GetVitesse())
		{
			heros->m_ChoixCompHeros();
			if(monstre.m_GetPV()!=0)
				monstre.m_ChoixCompMonstre();
		}
		else
		{
			monstre.m_ChoixCompMonstre();
			if(heros->m_GetPV()!=0)
				heros->m_ChoixCompHeros();
		}

		if(heros->m_GetPV()==0 or monstre.m_GetPV()==0)
			fin_cbt=true;

							
	}
}


