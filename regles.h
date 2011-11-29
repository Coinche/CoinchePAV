#ifndef REGLES_H
#define REGLES_H

#include "types.h"
#include "carte.h"
#include <map>



class Regles {
public:

    //Méthodes

    static int comparer(const Carte& carte1, const Carte& carte2, const Couleur& atout);
    //Renvoie :
        // 1 si carte1>carte2
        // 0 si carte1<carte2
    static Main valides(const Main& main, const Couleur& atout, const Pli& pliEnCours); //type de retour à voir plus tard
    static int valeur(const Carte& carte, const Couleur& atout);
	static int valeur(const Pli& pli,  const Couleur& atout);
	//il manque sans doute plein de regles, mais c'est pas grave parce qu'on peut en ajouter sans trop de souci de casser le code.
	// on peut par exemple penser pouvoir gerer les variantes avec la chute a 160 points, le resultat minimum a 82pts, etc.
};

#endif //REGLES_H
