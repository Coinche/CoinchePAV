#ifndef DEBUGAGE_H
#define DEBUGAGE_H

#include "types.h"
#include "annonce.h"
#include "regles.h"
#include "carte.h"

class Debugage {
public:
	static bool debugage();
};

class T_ANNONCE {
public :
	static bool test000_creation();
	static bool test100_objet();
	static bool test500_comparaison();

	static bool test_T_ANNONCE();

};

class T_CARTE {
public :
	static bool test000_creation();
	static bool test050_getvaleur();
	static bool test060_getcouleur();
	static bool test100_objet();


	static bool test_T_CARTE();

};

class T_REGLES {
public :

	static bool test050_valeurcarte();
	static bool test060_valeurpli();
	static bool test100_comparer();
    static bool test200_valides();
    static bool test150_egalitecarte();
    static bool test160_egalitemain();
	static bool test_T_REGLES();

};



#endif //DEBUGAGE_H
