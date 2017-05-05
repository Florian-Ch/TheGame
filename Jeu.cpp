#include "Jeu.h"

using namespace std;

Jeux::Jeux(){
	etatJeux = e_Initialisation;
	end=false;
}

void Jeux::m_getJoueur(){

//affichage de l'exemple d'un personnage pour que le joueur sache à quoi les nombres correspondent
	system("cat config_joueur.txt; echo");
//affichage de tous les personnages avec leurs caractéristiques
	system("cd Joueur; c=1; for i in *; do echo \"$c si tu veux :\"; cat $i; echo; c=$(($c + 1)); done");
//calcul le nombre de héros disponibles pour le joueur
	FILE *stream=popen("cd Joueur; c=0; for i in *; do c=$(($c + 1)); done;echo $c","r");
	char nb[3];
	if (stream){
			fgets(nb, 3, stream);
	}
	pclose(stream);
	int nb_heros=atoi(nb);
//Choix du personnage
	string s_choix;
	int choix=0;
//	while(choix<1 || choix>nb_heros){
		Interface::m_afficherLigne("Quelle classe veux-tu pour ton personnage ?");
		choix=Interface::m_getIntegeur(1,nb_heros);
		s_choix=Interface::m_intTOstring(choix);
//		choix= Interface::m_stringTOint(s_choix);
//		if (choix<1 || choix>nb_heros){
//			Interface::m_afficherLigne("Impossible, merci de choisir un nombre entre 1 et "+Interface::m_intTOstring(nb_heros));
//		}
//	}
//Récupération du nom du personnage choisi
	string cmd("cd Joueur; c=1; for i in *; do if test $c -eq ");
	cmd+=s_choix;
	cmd+="; then echo $(basename $i .txt); fi; c=$(($c + 1)); done";
	FILE *stream_heros=popen(cmd.c_str(),"r");
	char heros_choisi[50];
	if (stream_heros){
		fgets(heros_choisi, 50, stream_heros);
	}
	pclose(stream_heros);
	string nomaff = "";
	for(int i=0; i<50; i++)
		if((int)heros_choisi[i] > 31)
			nomaff += heros_choisi[i];
		else
			break;
	string nomFichierJoueur ="./Joueur/"+nomaff+".txt";
	for (int i=0; i<nomaff.size(); i++){
		if (nomaff[i]=='_')
			nomaff[i]=' ';
	
	}
	Interface::m_afficherLigne("Tu incarneras : "+ nomaff);
//Initialisation du joueur
	heros= new Joueur(nomFichierJoueur);
}

void Jeux::m_selectDifficulty(){
	Interface::m_afficherLigne("Difficulté :");
	Interface::m_afficherLigne("1 pour Easy, 2 pour Medium, 3 pour Hard");
	int choix=Interface::m_getIntegeur(1, 3);
	difficulty=choix;
}

void Jeux::m_getMap(){
//Récupère le nombre de maps disponibles pour la difficulté choisie
	system("> ./Map/All_map.txt");
	string s_map=("find ./Map -name map");
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
	int num_map=rand()%(nb_map);
//Donne le nom de la map randomisée avec laquelle le joueur va jouer
	string d;
	if (difficulty==1) d='E';
	else if (difficulty==2) d='M';
	else if (difficulty==3) d='H';
	string s_num_map=Interface::m_intTOstring(num_map);
	string nom_map="map"+d+s_num_map+".txt";
//si la map n'est pas correcte
	if (carte.m_chargerCarte("Map/"+nom_map)==false){
		Interface::m_afficherLigne("Carte corrompue");
		etatJeux=e_FinDuJeu;
	}

}

void Jeux::m_update(){
	char monstre;
	if(etatJeux==e_Initialisation){
		system("chmod 700 delete~.sh");
		system("./delete~.sh");
		system("clear");
//		system("mpg123 Gladiator.mp3 2> /dev/null &");
		Interface::m_afficherLigne("________     ________     ___________________________");
		Interface::m_afficherLigne("   |   |_____||______    |  ____|_____||  |  ||______");
		Interface::m_afficherLigne("   |   |     ||______    |_____||     ||  |  ||______");
		Interface::m_afficherLigne("_____________________________________________________");
		Interface::m_afficherLigne("");
		Interface::m_afficherLigne("Appuyer sur ENTREE pour continuer");
		getchar();
		system("clear");
		ifstream saveJ("save/saveJoueur.txt", ios::in);
		int continuer=2;
		if(saveJ){
			Interface::m_afficherLigne("[1]Continuer la partie en cours");
			Interface::m_afficherLigne("[2]Nouvelle partie");
			continuer=Interface::m_getIntegeur(1, 2);
			if (continuer==1){
				string nomh;
				string res;
				getline(saveJ, nomh);
				getline(saveJ, res);
				int PV=Interface::m_stringTOint(res.c_str());
				getline(saveJ, res);
				int Mana=Interface::m_stringTOint(res.c_str());
				heros=new Joueur("Joueur/"+nomh+".txt", PV, Mana);
				saveJ.close();
				carte.m_chargerCarte("save/saveMap.txt");
			}
		}
		if (continuer==2){
			m_getJoueur();
			m_selectDifficulty();
			m_getMap();
		}
			system("clear");
			Interface::m_afficherLigne("Utiliser z pour aller vers le haut, q vers la gauche, s vers le bas et d vers la droite");
			Interface::m_afficherLigne("Appuyer sur m pour afficher la map entière");
			Interface::m_afficherLigne("Appuyer sur p pour sauvegarder");
			Interface::m_afficherLigne("Appuyer sur ! pour quitter");
			etatJeux=e_Exploration;
	}

	else if(etatJeux==e_Exploration){
		carte.m_afficherCarte();
		char getcmd[7];
		getcmd[0]='z';	//Avancer
		getcmd[1]='q';	//Gauche
		getcmd[2]='s';	//Reculer
		getcmd[3]='d'; 	//Droite
		getcmd[4]='m';	//Afficher la map
		getcmd[5]='p';	//Sauvegarder
		getcmd[6]='!';	//Quitter
		char cmd=Interface::m_getChar(&getcmd[0], 7);
		if (cmd=='z')
			carte.m_deplacerHaut();
		if (cmd=='q')
			carte.m_deplacerGauche();
		if (cmd=='s')
			carte.m_deplacerBas();
		if (cmd=='d')
			carte.m_deplacerDroite();
		if (cmd=='m'){
			carte.m_displayMap();
			Interface::m_afficherLigne("Appuyer sur une lettre puis sur ENTREE pour continuer");
			Interface::m_attChar();
		}
		if (cmd=='p'){
			carte.m_save();
			system("> save/saveJoueur.txt");
			ofstream save("save/saveJoueur.txt", ios::out | ios::trunc);
			if (save){
				save<<heros->m_GetNom()<<endl;
				save<<heros->m_GetPV()<<endl;
				save<<heros->m_GetMana();
			}
			Interface::m_afficherLigne("Sauvergarde bien effectuée");
		}
		if (cmd=='!')
			etatJeux=e_FinDuJeu;
		if (carte.m_regenPV()==true){
			heros->m_RestaurerSante();
			Interface::m_afficherLigne("PV au max !");
		}
		if (carte.m_regenMana()==true){
			heros->m_RestaurerMana();
			Interface::m_afficherLigne("Mana au max !");
		}
		monstre=carte.m_getCombat();
		if (monstre!='0')
			etatJeux=e_Combat;
	}

	else if(etatJeux==e_Combat){
		string s="Monstre/"+string(1,monstre)+".txt";
		ifstream fichier(s.c_str(), ios::in);
		string s_nom;
		if(fichier){
			string ligne;
			getline(fichier, ligne);
			if (ligne[0]=='*'){
				for (int i=0; i<ligne.size()-1; i++)
					s_nom+=ligne[i+1];
			}
			else
				s_nom=string(1,monstre);
			fichier.close();
		}
		else
			Interface::m_afficherLigne("Fichier non ouvert");
		Combat fight(heros,s_nom);
		bool fuite=fight.m_CombatLancement();
		system("clear");
		if (!fuite)
			carte.m_fuite();
		else
			carte.m_mortMonstre();
		if(heros->m_GetPV()==0 || carte.m_resteMonstre()==false)
			etatJeux=e_FinDuJeu;
		else
			etatJeux=e_Exploration;
	}

	else if(etatJeux==e_FinDuJeu){
		if(heros->m_GetPV()==0)
			Interface::m_afficherLigne("Game Over");
		else if(carte.m_resteMonstre()==false)
			Interface::m_afficherLigne("Félicitations vous avez gagné");
		else
			Interface::m_afficherLigne("Partie finie");
//rejouer ou non
		carte.m_reset();
		carte = Map();
		Interface::m_afficherLigne("Voulez-vous rejouer ? (0 pour oui, 1 pour non) : ");
		int choix=Interface::m_getIntegeur(0,1);	
		if (choix==0){
			system("./JDR");
			end=true;
		}
		if (choix==1){
			system("clear");
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
