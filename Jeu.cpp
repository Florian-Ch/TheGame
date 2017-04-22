
#include "Jeu.h"
#include "Map.h"
#include "Joueur.h"
#include "Combat.h"
#include "Interface.h"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

Jeux::Jeux(){
	etatJeux = e_Initialisation;
	end=false;
}

void Jeux::m_getJoueur(){

//affichage de l'exemple d'un personnage pour que le joueur sache à quoi les nombres correspondent
	system("cat config_joueur.txt; echo");
//affichage de tous les personnages avec leurs caractéristiques
	system("cd Personnage/Joueur; c=1; for i in *; do echo \"$c si tu veux :\"; cat $i; echo; c=$(($c + 1)); done");
//calcul le nombre de héros disponibles pour le joueur
	FILE *stream=popen("cd Personnage/Joueur; c=0; for i in *; do c=$(($c + 1)); done;echo $c","r");
	char nb[3];
	if (stream){
			fgets(nb, 3, stream);
	}
	pclose(stream);
	int nb_heros=atoi(nb);
//Choix du personnage
	string s_choix;
	int choix=0;
	while(choix<1 || choix>nb_heros){
		m_afficherLigne("Quelle classe veux-tu pour ton personnage ?");
		getline(cin, s_choix);
		choix=atoi(s_choix);
		if (choix<1 || choix>nb_heros){
			m_afficherLigne("Impossible, merci de choisir un nombre entre 1 et "+nb_heros);
		}
	}
//Récupération du nom du personnage choisi
	string cmd("cd Personnage/Joueur; c=1; for i in *; do if test $c -eq ");
	cmd+=s_choix;
	cmd+="; then echo $(basename $i .txt); fi; c=$(($c + 1)); done";
	FILE *stream_heros=popen(cmd.c_str(),"r");
	char heros_choisi[50];
	if (stream_heros){
		fgets(heros_choisi, 50, stream_heros);
	}
	pclose(stream_heros);
	m_afficherLigne("Tu incarneras : "+heros_choisi);
//Initialisation du joueur
	heros=jouer(heros_choisi);
}

void Jeux::m_selectDifficulty(){
	m_afficherLigne("Difficulté :");
	m_afficherLigne("1 pour Easy, 2 pour Medium, 3 pour Hard");
	int choix=m_getIntegeur(1, 3);
	difficulty=choix;
}

void Jeux::m_getMap(){
//Récupère le nombre de maps disponibles pour la difficulté choisie
	system("> ./Map/All_map.txt");
ntToString	string s_map=("find ./Map -name map");
	if (difficulty==1) s_map+='E';
	else if (difficulty==2) s_map+='M';
	else if (difficulty==3) s_map+='H';
	else s_map=s_map;
	s_map+="* | cut -f3 -d\"/\" | cut -f1 -d\".\" >> ./Map/All_map.txt; grep \"\" -c ./Map/All_map.txt";
	FILE *stream_map=popen(s_map.c_str(),"r");
	char s_nb_map[3];
	if (stream_map){
		fgets(s_nb_map, 3, stream_map);
	}
	pclose(stream_map);
	int nb_map=atoi(s_nb_map);
	system("rm ./Map/All_map.txt");
//Sélectionne une map au hasard dans la difficulté
	int num_map=rand()%(nb_map)+1;
//Donne le nom de la map randomisée avec laquelle le joueur va jouer
	string d;
	if (difficulty==1) d='E';
	else if (difficulty==2) d='M';
	else if (difficulty==3) d='H';
	string s_num_map=m_intToString(num_map);
	string nom_map="map"+d+s_num_map;
	carte.m_chargerCarte(nom_map);
//si la map n'est pas correcte
	if (m_chargerCarte(nom_map)==false){
		m_afficherLigne("Carte corrompue");
		etatJeux=e_FinDuJeu;
	}

}

void Jeux::m_update(){
	if(etatJeux==e_Initialisation){
		m_getJoueur();
		m_selectDifficulty();
		m_getMap();
		carte.m_afficherCarte();
		etatJeux=e_Exploration;
	}

	else if(etatJeux==e_Exploration){
		char direction[4];
		direction[0]=z	//Avancer
		direction[1]=q	//Gauche
		direction[2]=s	//Reculer
		direction[3]=d	//Droite
		char mouvement=m_getChar(* direction, 4);
		if (mouvement=='z')
			carte.m_deplacerHaut();
		if (mouvement=='q')
			carte.m_deplacerGauche();
		if (mouvement=='s')
			carte.m_deplacerBas();
		if (mouvement=='d')
			carte.m_deplacerDroite();
		carte.m_afficherCarte();
		if (carte.m_getCombat==true){
			etatJeux=e_Combat;
		}
	}

	else if(etatJeux==e_Combat){
		Combat fight(heros,adversaire);
		fight.m_CombatLancement();
		if(heros.m_getPV()==0 || carte.m_resteMonstre()==false)
			etatJeux=e_FinDuJeu;
		else
			etatJeux=e_Exploration;
	}

	else if(etatJeux==e_FinDuJeu){
		if(heros.m_getPV()==0)
			m_afficherLigne("Game Over");
		else if(carte.m_resteMonstre()==false)
			m_afficherLigne("Félicitations vous avez gagné");
		else
			m_afficherLigne("Partie finie");
//rejouer ou non
		cout<<"Voulez-vous rejouer ? (0 pour oui, 1 pour non) : ";
		int choix=m_getIntegeur(int 0, int 1);	
		if (choix==0){
			etatJeux=e_Initialisation;
		}
		if (choix==1){
			end=true;
		}
	}
}

bool Jeux::m_getEtat(){
	if(end==true) return false;
	if(end==false) return true;
}

Jeux::~Jeux(){
	delete heros;
}
