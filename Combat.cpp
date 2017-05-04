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
	int n=Interface::m_getIntegeur(0, heros->m_GetNbrCompetence());
	if(n!=0) 								
		heros->m_UtiliserCompetence(n-1,&monstre);					
}

void Combat::m_ChoixCompMonstre()						//Méthode qui définit l'IA du monstre à améliorer
{

	int memo_comp;
	int pv_max_perdu;
	pv_max_perdu=heros->m_GetPVMax();
	
	Joueur* copie_heros;
	copie_heros=heros;

	for(int i=0;i<m_GetNbrCompetece();i++)
	{
		monstre._UtiliserCompetence(i,copie_heros);
		if(copie_heros->m_GetPV() <= pv_max_perdu)
		{
			pv_max_perdu=copie_heros->m_GetPV();
			memo_comp=i;
			copie_heros->m_RestaurerSante();
			
		}
	}

	monstre.m_UtiliserCompetence(memo_comp,heros);
}

void Combat::m_Affichage()
{
	system("clear");
	Interface::m_afficherLigne(heros->m_GetNom()+":");
	Interface::m_afficherLigne("Pv : "+Interface::m_intTOstring(heros->m_GetPV()));
	Interface::m_afficherLigne("Mana : "+Interface::m_intTOstring(heros->m_GetMana()));
	Interface::m_afficherLigne("[0]Passer le tour");
	heros->m_GetAllCompetence();
	Interface::m_afficherLigne(monstre.m_GetNom());
	Interface::m_afficherLigne("Pv : "+Interface::m_intTOstring(monstre.m_GetPV()));
	Interface::m_afficherLigne("Mana : "+Interface::m_intTOstring(monstre.m_GetMana()));
}



void Combat::m_CombatLancement()
{

	

	while(fin_cbt==false)
	{
		
		m_Affichage();
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
		cout<<"PV heros : "<<heros->m_GetPV()<<endl;
		cout<<"PV monstre : "<<monstre.m_GetPV()<<endl;
		if(heros->m_GetPV()==0 || monstre.m_GetPV()==0)
			fin_cbt=true;
	}
}


