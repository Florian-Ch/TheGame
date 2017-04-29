#include "Map.h"


using namespace std;

Map::Map(){
	tailleCarteX=0;
	tailleCarteY=0;
}

Map::~Map(){

}

void Map::m_deplacerHaut(){
	if (carte[posX][posY-1]!=0 && posY!=0)
		posY=posY-1;
	else
		Interface::m_messageErreur("BOUM ! Un mur !");
}

void Map::m_deplacerBas(){
	if (carte[posX][posY+1]!=0 && posY!=tailleCarteY-1)
		posY=posY+1;
	else
		Interface::m_messageErreur("BOUM ! Un mur !");
}

void Map::m_deplacerGauche(){
	if (carte[posX-1][posY]!=0 && posX!=0)
		posX=posX-1;
	else
		Interface::m_messageErreur("BOUM ! Un mur !");
}

void Map::m_deplacerDroite(){
	if (carte[posX+1][posY]!=0 && posX!=tailleCarteX-1)
		posX=posX+1;
	else
		Interface::m_messageErreur("BOUM ! Un mur !");
}

void Map::m_afficherCarte(){
	if(tailleCarteX<15 && tailleCarteY<15){
cout<<"ici1"<<endl;
		for (int i=0; i<tailleCarteX; i++){
			for (int j=0; j<tailleCarteY; j++)
				Interface::m_afficherChar(carte[i][j]);
//			Interface::m_afficherLigne("");
		}
	}
	else if (posX-5<0){
cout<<"ici2"<<endl;
		for (int i=0; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++)
				Interface::m_afficherChar(carte[i][j]);
			Interface::m_afficherLigne("");
		}
	}
	else if (posY-5<0){
cout<<"ici3"<<endl;
		for (int i=posX-5; i<posX+6; i++){
			for (int j=0; j<posY+6; j++)
				Interface::Interface::m_afficherChar(carte[i][j]);
			Interface::Interface::m_afficherLigne("");
		}
	}
	else if (posX+6>=tailleCarteX){
cout<<"ici4"<<endl;
		for (int i=posX-5; i<tailleCarteX; i++){
			for (int j=posY-5; j<posY+6; j++)
				Interface::m_afficherChar(carte[i][j]);
			Interface::m_afficherLigne("");
		}
	}
	else if (posY+6>=tailleCarteY){
cout<<"ici5"<<endl;
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<tailleCarteY; j++)
				Interface::m_afficherChar(carte[i][j]);
			Interface::m_afficherLigne("");
		}
	}
	else {
cout<<"ici6"<<endl;
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++)
				Interface::m_afficherChar(carte[i][j]);
			Interface::m_afficherLigne("");
		}		
	}
}

bool Map::m_chargerCarte(string nomMap){
	string pathMap="Map/"+nomMap;
cout<<pathMap<<endl;
	ifstream mapTxt;
	mapTxt.open(pathMap.c_str());
//récupération de la taille de la map
	if(mapTxt){
		int maxSizeLine=0;
		string line;
		while(getline(mapTxt, line)){
			if(line.size()>maxSizeLine)
				maxSizeLine = line.size();
			tailleCarteY++;
		}
		tailleCarteX = maxSizeLine;		
		mapTxt.close();
	}
	else
		Interface::m_afficherLigne("Map non ouverte");
//création de la carte et initialisation de toutes les cases à ' '
	carte = new char*[tailleCarteX];
	for (int i=0; i<tailleCarteX; i++){
		carte[i]=new char[tailleCarteY];
		for (int j=0; j<tailleCarteY; j++)
			carte[i][j]=' ';
	}
//mapTxt → Tableau
	mapTxt.open(pathMap.c_str());
	if(mapTxt){
		char lettre;
		int i=0, j=0;
cout<<"Map :"<<endl;
		while(mapTxt.get(lettre)){
			carte[i][j]=lettre;
			cout<<carte[i][j];
			if (j==tailleCarteY-1){
				i++;
				j=0;
			cout<<endl;
			}
			else
				j++;
		}
cout<<"fin map"<<endl;
cout<<"fdskjljfls :"<<carte[tailleCarteX-1][tailleCarteY-1]<<endl;
		mapTxt.close();
	}
//Détection point de spawn
	int nbSpawn=0;
	cout<<"taille : "<<tailleCarteX<<" "<<tailleCarteY<<endl;
	for (int i=0; i<tailleCarteX; i++){
		for (int j=0; j<tailleCarteY; j++){
			if (carte[i][j]=='1')
				nbSpawn++;
		}
	}
	if (nbSpawn==1){
		Interface::m_afficherLigne("Chargement de la carte");
		for (int i=0; i<tailleCarteX; i++){
			for (int j=0; j<tailleCarteY; j++){
				if (carte[i][j]=='1')
					posX=i;
					posY=j;
			}
		}
		return true;
	}
	else{
		Interface::m_messageErreur("Map impossible, nombre de points de spawn != 1, désolé !");
		return false;
	}
}

bool Map::m_resteMonstre(){
	int nbMonstres=0;
	for (int i=0; i<tailleCarteX; i++){
		for (int j=0; j<tailleCarteY; j++){
			if (carte[i][j]!='0' && carte[i][j]!='1' && carte[i][j]!='2' && carte[i][j]!='3' && carte[i][j]!='4')
				nbMonstres++;
		}
	}
	if (nbMonstres==0)
		return false;
	else
		return true;
}

char Map::m_getCombat(){
	if(!(carte[posX][posY] >= '0' && carte[posX][posY] <= '4'))
		return carte[posX][posY];
	else
		return '0';
}
