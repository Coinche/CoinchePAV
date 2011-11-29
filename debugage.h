#ifndef DEBUGAGE_H
#define DEBUGAGE_H

#include "types.h"
#include "annonce.h"
#include "regles.h"
#include "carte.h"
#include "mmain.h"


class Debugage {
public:
	static bool debugage();
	static bool test_T_ANNONCE();
	static bool test_T_CARTE();
	static bool test_T_MMAIN();
	static bool test_T_REGLES();
private:

};
/*
class T_JOUEUR {
public :
	static bool test000_creation();
	static bool test100_objet();
	static bool test150_encheresencours();
	static bool test200_melanger();
	static bool test250_distribuer();
	static bool test300_compter();
	static bool test400_jouerUnpli();
	static bool test450_jouerUntour();
	static bool test500_comparaison();

	static bool test_T_JOUEUR();

};
*/



#endif //DEBUGAGE_H
