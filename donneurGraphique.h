<<<<<<< HEAD
#ifndef DONNEUR_GRAPHIQUE_H
#define DONNEUR_GRAPHIQUE_H

#include "annonce.h"
#include "carte.h"

//classe virtuelle pour pouvoir bien specifier une interface entre graphique et métier indépendante de la librarie graphique
//et compiler la partie metier seule (sous forme de librarie statique)
class DonneurGraphique {
public:
	virtual void afficherAnnonce(int joueur, const Annonce&) = 0;
	virtual void afficherCarte(int joueur, const Carte& ) = 0;
	virtual void ramasserPli() = 0;
};

=======
#ifndef DONNEUR_GRAPHIQUE_H
#define DONNEUR_GRAPHIQUE_H

#include "annonce.h"
#include "carte.h"

//classe virtuelle pour pouvoir bien specifier une interface entre graphique et métier indépendante de la librarie graphique
//et compiler la partie metier seule (sous forme de librarie statique)
class DonneurGraphique {
public:
	virtual void afficherAnnonce(int joueur, const Annonce& annonce) = 0;
	virtual void afficherCarte(int joueur, const Carte& carte) = 0;
	virtual void ramasserPli() = 0;
};

>>>>>>> 724574f908be7f7cad89d404f7c1f8c54b5cda57
#endif //DONNEUR_GRAPHIQUE_H