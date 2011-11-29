test.exe: annonce.o carte.o debugage.o donneur.o joueur.o main.o mmain.o regles.o
	g++ -Wall -o test.exe *.o

annonce.o: types.h
carte.o: types.h
debugage.o: types.h annonce.h regles.h carte.h
donneur.o: regles.h joueur.h donneurGraphique.h
joueur.o: carte.h annonce.h
main.o: types.h annonce.h debugage.h donneur.h
mmain.o: carte.h
regles.o: types.h carte.h

%.o:%.cpp %.h
	g++ -Wall -c -o $@ $<
	
clean:
	del *.o test.exe