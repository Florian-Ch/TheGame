/*!
\file Jeu.h
\brief Header de la classe Map
\author Florian
\date 22 avril 2017
\version 1
*/

/*! \class Map Map.h
    \brief classe Map

    Gère le fonctionnement de la carte général
*/

class Map{
private:
	char** carte;			//!< Tableau de caractères de 2 dimensions représentant la map
	int posX;			//!< Position du joueur (abscisse)
	int posY;			//!< Position du joueur (ordonnée)
	int tailleCarteX;		//!< Taille de la carte (horizontale)
	int tailleCarteY;		//!< Taille de la carte (verticale) 
public:
/*!
\brief Constructeur
Initialise la taille de la carte à (0;0)
*/
	Map();
/*!
\brief Déplacement du joueur vers le haut
*/
	void m_déplacerHaut();
/*!
\brief Déplacement du joueur vers le bas
*/
	void m_déplacerBas();
/*!
\brief Déplacement du joueur vers la gauche
*/
	void m_déplacerGauche();
/*!
\brief Déplacement du joueur vers la droite
*/
	void m_déplacerDroite();
/*!
\brief Affiche la carte
Affiche 5 cases de chaque coté du joueur si la taille de la carte et le positionnement du joueur le permettent
*/
	void m_afficherCarte();
/*!
\brief Charge la carte
\param string nom du fichier map à charger
\return true si la map est possible
\return false si la map est techniquement impossible (ex: il n'y a pas de spawn pour le joueur)
*/
	bool m_chargerCarte(string);
/*!
\brief Booléen pour savoir s'il reste des monstres sur la carte
\return true s'il reste des monstres
\return false si tous les monstres ont été vaincus
*/
	bool m_resteMonstre();
/*!
\brief Destructeur
*/
	~Map();
};
