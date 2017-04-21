#include "Personnage.cpp"

class Combat
{

	private:
	
	Joueur* heros;		
	Monstre monstre;	
	bool fin_cbt;

	public:

	Combat(Joueur*,Monstre);
	void m_CombatLancement();
	void m_Affichage();
	void m_ChoixCompHeros();
	void m_ChoixCompMonstre();
	
};


