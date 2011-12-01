<<<<<<< HEAD
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
=======
test.exe: annonce.o carte.o debugage.o donneur.o joueur.o main.o mmain.o regles.o joueurHumain.o
	g++ -Wall -o test.exe *.o

annonce.o: types.h
carte.o: types.h
debugage.o: types.h annonce.h regles.h carte.h
donneur.o: regles.h joueur.h donneurGraphique.h
joueur.o: carte.h annonce.h
main.o: types.h annonce.h debugage.h donneur.h
mmain.o: carte.h
regles.o: types.h carte.h
joueurHumain.o: mmain.h annonce.h joueur.h joueurhumaingraphique.h
%.o:%.cpp %.h
	g++ -Wall -c -o $@ $<
	
clean:
>>>>>>> 724574f908be7f7cad89d404f7c1f8c54b5cda57
	del *.o test.exe