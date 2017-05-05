#include "Map.h"


using namespace std;

Map::Map(){
	tailleCarteX=0;
	tailleCarteY=0;
	memory='0';
}

Map::~Map(){
	
}

void Map::m_deplacerHaut(){
	if (posX==0)
		Interface::m_afficherLigne("BOUM ! Un mur !");
	else if (carte[posX-1][posY]!='0'){
		carte[posX][posY]='4';
		posX=posX-1;
		memory=carte[posX][posY];
		carte[posX][posY]='+';
	}
	else{
		Interface::m_afficherLigne("BOUM ! Un mur !");
	}
}

void Map::m_deplacerBas(){
	if (carte[posX+1][posY]!='0' && posX!=tailleCarteX-1){
		carte[posX][posY]='4';
		posX=posX+1;
		memory=carte[posX][posY];
		carte[posX][posY]='+';
	}
	else
		Interface::m_afficherLigne("BOUM ! Un mur !");
}

void Map::m_deplacerGauche(){
	if (posY==0)
		Interface::m_afficherLigne("BOUM ! Un mur !");
	else if (carte[posX][posY-1]!='0'){
		carte[posX][posY]='4';
		posY=posY-1;
		memory=carte[posX][posY];
		carte[posX][posY]='+';
	}
	else
		Interface::m_afficherLigne("BOUM ! Un mur !");
}

void Map::m_deplacerDroite(){
	if (carte[posX][posY+1]!='0' && posY!=tailleCarteY-1){
		carte[posX][posY]='4';
		posY=posY+1;
		memory=carte[posX][posY];
		carte[posX][posY]='+';
	}
	else
		Interface::m_afficherLigne("BOUM ! Un mur !");
}

void Map::m_afficherCarte(){
	if(tailleCarteX<15 && tailleCarteY<15){
		for (int i=0; i<tailleCarteX; i++){
			for (int j=0; j<tailleCarteY; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY<6 && posX<6){
		for (int i=0; i<posX+6; i++){
			for (int j=0; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY+6>tailleCarteY && posX+6>tailleCarteX){
		for (int i=posX-5; i<tailleCarteX; i++){
			for (int j=posY-5; j<tailleCarteY; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY+6>tailleCarteY && posX<6){
		for (int i=0; i<posX+6; i++){
			for (int j=posY-5; j<tailleCarteY; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY<6 && posX+6>tailleCarteX){
		for (int i=posX-5; i<tailleCarteX; i++){
			for (int j=0; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posX<6){
		for (int i=0; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY<6){
		for (int i=posX-5; i<posX+6; i++){
			for (int j=0; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::Interface::m_afficherLigne("");
		}
	}
	else if (posX+6>tailleCarteX){
		for (int i=posX-5; i<tailleCarteX; i++){
			for (int j=posY-5; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else if (posY+6>tailleCarteY){
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<tailleCarteY; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}
	}
	else {
		for (int i=posX-5; i<posX+6; i++){
			for (int j=posY-5; j<posY+6; j++){
				if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
					Interface::m_afficherChar('4');
				else
					Interface::m_afficherChar(carte[i][j]);
			}
			Interface::m_afficherLigne("");
		}		
	}
}

void Map::m_displayMap(){
	for (int i=0; i<tailleCarteX; i++){
		for (int j=0; j<tailleCarteY; j++){
			if (!(carte[i][j] >= '0' && carte[i][j] <= '4') && carte[i][j]!='+')
				Interface::m_afficherChar('4');
			else
				Interface::m_afficherChar(carte[i][j]);
		}
		Interface::m_afficherLigne("");
	}
}

bool Map::m_chargerCarte(string nomMap){
	Interface::m_afficherLigne("Chargement de la carte");
	string pathMap=nomMap;
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
	int max=tailleCarteX;
	if(tailleCarteY>tailleCarteX)
		max=tailleCarteY;
	tailleCarteX=max;
	tailleCarteY=max;
	carte = new char*[max];
	for (int i=0; i<max; i++){
		carte[i]=new char[max];
		for (int j=0; j<max; j++)
			carte[i][j]='0';
	}
//mapTxt → Tableau
	mapTxt.open(pathMap.c_str());
	if(mapTxt){
		char lettre;
		string ligne;
		int j=0;
		while(getline(mapTxt, ligne)){
			for(int i=0; i<ligne.size(); i++){
				if ((int)ligne[i]>31){
					carte[j][i]=ligne[i];
				}
			}
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
				if (carte[i][j]=='1'){
					posX=i;
					origineX=i;
					posY=j;
					origineY=j;
					carte[i][j]='+';
				}
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
			if (carte[i][j]!='0' && carte[i][j]!='1' && carte[i][j]!='2' && carte[i][j]!='3' && carte[i][j]!='4' && carte[i][j]!='+')
				nbMonstres++;
		}
	}
	if (nbMonstres==0)
		return false;
	else
		return true;
}

char Map::m_getCombat(){
	if(!(memory >= '0' && memory <= '4') && memory!='+')
		return memory;
	else
		return '0';
}

void Map::m_mortMonstre(){
	memory='4';
}

void Map::m_reset(){
	for (int i=0; i<tailleCarteX; i++)
		delete carte[i];
	delete[] carte;
}

bool Map::m_regenPV(){
	if (memory == '2'){
		return true;
	}
	else 
		return false;
}

bool Map::m_regenMana(){
	if (memory == '3'){
		return true;
	}
	else 
		return false;
}

void Map::m_fuite(){
	carte[posX][posY]=memory;
	posX=origineX;
	posY=origineY;
	carte[posX][posY]='+';
}

void Map::m_save(){
	int stocki, stockj;
	for (int i=0; i<tailleCarteX; i++){
		for (int j=0; j<tailleCarteY; j++){
			if (carte[i][j]=='+'){
				stocki=i;
				stockj=j;
				carte[i][j]='1';
			}
		}
	}
	system("> save/saveMap.txt");
	ofstream save("save/saveMap.txt", ios::out | ios::trunc);
	if (save){
		for (int i=0; i<tailleCarteX; i++){
			for (int j=0; j<tailleCarteY; j++){
				save.put(carte[i][j]);
			}
			save<<endl;
		}
		carte[stocki][stockj]='+';
		save.close();
	}
	else
		Interface::m_afficherLigne("Sauvegarde impossible, fichier non trouve");
}

