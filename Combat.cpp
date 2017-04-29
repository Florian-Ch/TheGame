#include "Combat.h"

using namespace std;

Combat::Combat(Joueur* h,string m): monstre(m)
{
	heros=h;
	fin_cbt=false;
}

void Combat::m_ChoixCompHeros()							//Méthode qui permet au joueur de choisir une compétence a utiliser
{
	
	Interface::m_afficherLigne("C'est a votre tour, quelle compétence voulez vous utiliser ?"); 	
	
	int n = Interface::m_getIntegeur(0, heros->m_GetNbrCompetence());								
	heros->m_UtiliserCompetence(n,&monstre);					
}

void Combat::m_ChoixCompMonstre()						//Méthode qui définit l'IA du monstre à améliorer
{

	int nbc=monstre.m_GetNbrCompetence();					//Recup le nbr de comp du monstre
	int m=rand()%nbc;							//Genre un nombre aléatoire pour savoir qu'elle comp utiliser
	monstre.m_UtiliserCompetence(m,heros);
	Interface::m_afficherLigne("Le monstre vient de jouer");				
}

void Combat::m_Affichage()
{
	system("clear");
	Interface::m_afficherLigne(heros->m_GetNom()+":");
	Interface::m_afficherLigne("Pv:"+heros->m_GetPV());
	Interface::m_afficherLigne("Mana:"+heros->m_GetMana());
	vector<string> allComp= heros->m_GetAllCompetence();
	for(int i=0; i< allComp.size();i++)
		Interface::m_afficherLigne(allComp[i]);

	Interface::m_afficherLigne(monstre.m_GetNom()+":");
	Interface::m_afficherLigne("Pv:"+monstre.m_GetPV());
	Interface::m_afficherLigne("Mana:"+monstre.m_GetMana());
}

void Combat::m_CombatLancement()
{

	m_Affichage();

	while(fin_cbt==false)
	{
		if(heros->m_GetVitesse()>monstre.m_GetVitesse())
		{
			m_ChoixCompHeros();
			if(monstre.m_GetPV()!=0)
				m_ChoixCompMonstre();
		}
		else
		{
			m_ChoixCompMonstre();
			if(heros->m_GetPV()!=0)
				m_ChoixCompHeros();
		}

		if(heros->m_GetPV()==0 or monstre.m_GetPV()==0)
			fin_cbt=true;

							
	}
}


