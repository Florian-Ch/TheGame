#include "Map.h"
#include <fstream>
#include <string>

using namespace std;

Map::Map(){
	tailleCarteX=0;
	tailleCarteY=0;
}

void Map::m_déplacerHaut(){
	if (carte[posX][posY-1]!=0 && posY!=0)
		posY=posY-1;
	else
		m_messageErreur("BOUM ! Un mur !");
}

void Map::m_déplacerBas(){
	if (carte[posX][posY+1]!=0 && posY!=tailleCarteY-1)
		posY=posY+1;
	else
		m_messageErreur("BOUM ! Un mur !");
}

void Map::m_déplacerGauche(){
	if (carte[posX-1][posY]!=0 && posX!=0)
		posX=posX-1;
	else
		m_messageErreur("BOUM ! Un mur !");
}

void Map::m_déplacerDroite(){
	if (carte[posX+1][posY]!=0 && posX!=tailleCarteX-1)
		posX=posX+1;
	else
		m_messageErreur("BOUM ! Un mur !");
}

void Map::m_afficherCarte(){
	if(tailleCarteX<15 && tailleCarteY<15){
		for (int i=0; i<tailleCarteX; i++){
			for (int j=0; j<tailleCarteY; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}
	}
	else if (posX-5<0){
		for (int i=0; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}
	}
	else if (posY-5<0){
		for (int i=posX-5; i<posX+6; i++){
			for (int j=0; j<posY+6; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}
	}
	else if (posX+6>=tailleCarteX){
		for (int i=posX-5; i<tailleCarteX; i++){
			for (int j=posY-5; j<posY+6; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}
	}
	else if (posY+6>=tailleCarteY){
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<tailleCarteY; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}
	}
	else {
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++)
				m_afficherChar(carte[i][j]);
			m_afficherLigne("");
		}		
	}
}

bool Map::m_chargerCarte(string nomMap){
	string pathMap="/Map/"+nomMap;
	ifstream mapTxt(pathMap, ios::in);
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
//création de la carte et initialisation de toutes les cases à ' '
	carte = new char*[tailleCarteX];
	for (int i=0; i<tailleCarteX; i++){
		carte[i]=new char[tailleCarteY];
		for (int j=0; j<tailleCarteY; j++)
			carte[i][j]=' ';
	}
//mapTxt → Tableau
	if(mapTxt){
		char lettre;
		int i=0, j=0;
		while(mapTxt.get(lettre)){
			carte[i][j]=lettre;
			if (j==tailleCarteY-1){
				i++;
				j=0;
			}
			else
				j++;
		}
		mapTxt.close();
	}
//Détection point de spawn
	int nbSpawn=0;
	for (int i=0; i<tailleCarteX; i++){
		for (int j=0; j<tailleCarteY; j++){
			if (carte[i][j]=='1')
				nbSpawn++;
		}
	}
	if (nbSpawn==1){
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
		m_messageErreur("Map impossible, nombre de points de spawn != 1, désolé !");
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
