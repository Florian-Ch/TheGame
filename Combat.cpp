#include "Combat.h"

using namespace std;

Combat::Combat(Joueur* h,string m)
{
	heros=h;
	fin_cbt=false;

	std::string q="";	

	for(int v=0;v<m.size();v++)
	{
		q+=m[v];
		tab_monstre.push_back(Monstre(q));
		q="";
	}
}

void Combat::m_ChoixCompHeros()							//Méthode qui permet au joueur de choisir une compétence a utiliser
{
	
	Interface::m_afficherLigne("C'est a votre tour, quelle compétence voulez vous utiliser ?");
	int n=Interface::m_getIntegeur(0, heros->m_GetNbrCompetence()+1);
	if(n!=0 && n!=(heros->m_GetNbrCompetence()+1))
	{
		if(tab_monstre.size()>1)
		{
	 		Interface::m_afficherLigne("Quel monstre voulez vous ciblez ?");
			int o=Interface::m_getIntegeur(0, heros->m_GetNbrCompetence());							
			heros->m_UtiliserCompetence(n-1,&tab_monstre[o-1]);
		}
		else
		{
			heros->m_UtiliserCompetence(n-1,&tab_monstre[0]);
		}
		
	}
	if(n==(heros->m_GetNbrCompetence()+1))
		fin_cbt=true;					
}

void Combat::m_ChoixCompMonstre()						//Méthode qui définit l'IA du monstre à améliorer
{

	for(int i=0;i<tab_monstre.size();i++)
	{
		if(tab_monstre[i].m_GetPV()!=0)
		{
			int memo_comp;
			int pv_max_perdu;
			pv_max_perdu=heros->m_GetPVMax();
			
			string nomh=heros->m_GetNom();
			for (int cp=0; cp<nomh.size(); cp++){
				if (nomh[cp]==' ')
					nomh[cp]='_';
			}
			
			Joueur* copie_heros=new Joueur("./Joueur/"+nomh+".txt");
			copie_heros->m_RestaurerSante();
			
			int mana_dbt=tab_monstre[i].m_GetMana();

			for(int l=0;l<tab_monstre[i].m_GetNbrCompetence();l++)
			{
				tab_monstre[i].m_UtiliserCompetenceSA(l,copie_heros);

				if(copie_heros->m_GetPV() <= pv_max_perdu)
				{
			
					pv_max_perdu=copie_heros->m_GetPV();
					memo_comp=l;
					copie_heros->m_RestaurerSante();
					tab_monstre[i].m_setMana(mana_dbt);
			
				}
			}

			tab_monstre[i].m_UtiliserCompetence(memo_comp,heros);
		}

	}
}

void Combat::m_Affichage()
{
	
	Interface::m_afficherLigne(heros->m_GetNom()+":");
	Interface::m_afficherLigne("Pv : "+Interface::m_intTOstring(heros->m_GetPV())+"/"+Interface::m_intTOstring(heros->m_GetPVMax()));
	Interface::m_afficherLigne("Mana : "+Interface::m_intTOstring(heros->m_GetMana())+"/"+Interface::m_intTOstring(heros->m_GetManaMax()));
	Interface::m_afficherLigne("[0]Passer le tour");
	heros->m_GetAllCompetence();
	Interface::m_afficherLigne("["+Interface::m_intTOstring(heros->m_GetNbrCompetence()+1)+"]Prendre la fuite (le monstre aura la possibilité d'attaquer");
	
	for(int w=0;w<tab_monstre.size();w++)
	{
		if(tab_monstre.size()>1)
			Interface::m_afficherLigne(Interface::m_intTOstring(w+1)+":"+tab_monstre[w].m_GetNom());
		else
			Interface::m_afficherLigne(tab_monstre[w].m_GetNom());
		Interface::m_afficherLigne("Pv : "+Interface::m_intTOstring(tab_monstre[w].m_GetPV()));
		Interface::m_afficherLigne("Mana : "+Interface::m_intTOstring(tab_monstre[w].m_GetMana()));
		
		Interface::m_afficherLigne("");
	}
	
}



bool Combat::m_CombatLancement()
{
	system("clear");
	
	int pv_tot_monstre(0);

	while(fin_cbt==false)
	{
		//system("clear");
		
		pv_tot_monstre=0;
		
		m_Affichage();
		if(heros->m_GetVitesse()>tab_monstre[0].m_GetVitesse())
		{
			
			m_ChoixCompHeros();
			system("clear");
			m_ChoixCompMonstre();
		}
		else
		{
			system("clear");
			m_ChoixCompMonstre();
			m_Affichage();
			if(heros->m_GetPV()!=0)
				m_ChoixCompHeros();
		}

		for(int j=0;j<tab_monstre.size();j++)
			pv_tot_monstre += tab_monstre[j].m_GetPV();

		if(heros->m_GetPV()==0 || pv_tot_monstre==0)
			fin_cbt=true;
			
	}

	
	if(heros->m_GetPV()==0 || pv_tot_monstre==0)
		return true;
	else
		return false;
}


