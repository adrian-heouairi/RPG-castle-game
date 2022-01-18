CPP=g++ --std=c++11
CFLAGS= -Wall

all : main

main : main.o Amazone.o Arc.o Arme.o BaguetteMagique.o Baton.o CleDeTeleportation.o Epee.o Guerrier.o Moine.o Objet.o Personnage.o Piece.o PossedeInventaire.o PotionDePoison.o PotionDeSoin.o Sorciere.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

Amazone.o : Amazone.cpp Amazone.hpp
	$(CPP) $(CFLAGS) -c $<

Arc.o : Arc.cpp Arc.hpp
	$(CPP) $(CFLAGS) -c $<

Arme.o : Arme.cpp Arme.hpp
	$(CPP) $(CFLAGS) -c $<

BaguetteMagique.o : BaguetteMagique.cpp BaguetteMagique.hpp
	$(CPP) $(CFLAGS) -c $<

Baton.o : Baton.cpp Baton.hpp
	$(CPP) $(CFLAGS) -c $<

CleDeTeleportation.o : CleDeTeleportation.cpp CleDeTeleportation.hpp
	$(CPP) $(CFLAGS) -c $<

Epee.o : Epee.cpp Epee.hpp
	$(CPP) $(CFLAGS) -c $<

Guerrier.o : Guerrier.cpp Guerrier.hpp
	$(CPP) $(CFLAGS) -c $<

Moine.o : Moine.cpp Moine.hpp
	$(CPP) $(CFLAGS) -c $<

Objet.o : Objet.cpp Objet.hpp
	$(CPP) $(CFLAGS) -c $<

Personnage.o : Personnage.cpp Personnage.hpp
	$(CPP) $(CFLAGS) -c $<

Piece.o : Piece.cpp Piece.hpp
	$(CPP) $(CFLAGS) -c $<

PossedeInventaire.o : PossedeInventaire.cpp PossedeInventaire.hpp
	$(CPP) $(CFLAGS) -c $<

PotionDePoison.o : PotionDePoison.cpp PotionDePoison.hpp
	$(CPP) $(CFLAGS) -c $<

PotionDeSoin.o : PotionDeSoin.cpp PotionDeSoin.hpp
	$(CPP) $(CFLAGS) -c $<

Sorciere.o : Sorciere.cpp Sorciere.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o main

test: all
	./main
