JDR: main.o Combat.o Competence.o Interface.o Jeu.o Joueur.o Map.o Monstre.o Personnage.o
	g++ -o JDR main.o Combat.o Competence.o Interface.o Jeu.o Joueur.o Map.o Monstre.o Personnage.o

main.o: main.cpp
	g++ -c main.cpp

Combat.o: Combat.cpp Combat.h
	g++ -c Combat.cpp

Competence.o: Competence.cpp Competence.h
	g++ -c Competence.cpp

Interface.o: Interface.cpp Interface.h
	g++ -c Interface.cpp

Jeu.o: Jeu.cpp Jeu.h
	g++ -c Jeu.cpp

Joueur.o: Joueur.cpp Joueur.h
	g++ -c Joueur.cpp

Map.o: Map.cpp Map.h
	g++ -c Map.cpp

Monstre.o: Monstre.cpp Monstre.h
	g++ -c Monstre.cpp

Personnage.o: Personnage.cpp Personnage.h
	g++ -c Personnage.cpp
