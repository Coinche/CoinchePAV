#ifndef JOUEURIA_H
#define JOUEURIA_H

#include "joueur.h"
#include "carte.h"
#include "annonce.h"
#include "regles.h"
#include "donneur.h"

class IA : public Joueur {
public:
    void set_donneur(Donneur* _donneur);
protected:
    Donneur *donneur;
};

class IA_dummy : public IA {

//Classes héritées :
/*
	Annonce annoncer();
	Carte jouer();
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main get_main() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	void recevoirMain(const Main&);  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
*/

public:
        Annonce reflechirEtAnnoncer(const  std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles);
        Carte reflechirEtJouer(const Main& valides);
};

class IA_intermediate : public IA {

//Classes héritées :
/*
	Annonce annoncer();
	Carte jouer();
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main get_main() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	void recevoirMain(const Main&);  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
*/

public:
        Annonce reflechirEtAnnoncer(const std::pair<std::vector<Couleur>, std::vector<Hauteur> > &possibles);
        Carte reflechirEtJouer(const Main&);

private:
    Hauteur estimerValeurDeLaMain(const Couleur& atout);
    Hauteur estimerValeurMainAvecPartner(const Couleur& couleurdemandeeparpartner);
	Annonce MaximiserlAnnonceInitiale();
	Hauteur RenvoyerDerniereAnnonceDansLaCouleur(const Encheres& encheresIA, const Couleur& couleurdemandee);
    Hauteur RenvoyerPremiereAnnonceDansLaCouleur(const Encheres& encheresIA, const Couleur& couleurdemandee);

    int DeposerNefle(const Couleur& atout, const Main &valides);
    bool EstMaitre(const Carte& carteATester, const Couleur& atout, const Pli& PliEnCours);

    Couleur atout;
    Pli PliEnCours;
    unsigned int tourAlaCouleur[4]; // on compte les tours
    unsigned int cartesRestantesalaCouleur[4];


};

class IA_cheater : public Joueur {

//Classes héritées :
/*
	Annonce annoncer();
	Carte jouer();
	//si on le lui demande, le joueur doit dire quelles cartes il lui reste.
	Main get_main() const;  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
	void recevoirMain(const Main&);  //privée et amie avec Donneur?? peut-etre un peu trop keke dans un premier temps
*/

public:

	Annonce reflechirEtAnnoncer(const Annonce&);
	int reflechirEtJouer(const Annonce&);
	Main main;
};

#endif //JOUEURIA_H
