#ifndef JOUEURHUMAINGRAPHIQUE_H
#define JOUEURHUMAINGRAPHIQUE_H
#include "carte.h"
#include "annonce.h"

class JoueurHumainGraphique
{
public:
    virtual int afficherMainEtJouer(Main main,std::vector<bool> jouable) = 0;
    virtual void afficherMain(Main main,std::vector<bool> jouable) = 0;
    virtual Annonce afficherAnnonceEtParler(std::vector<Hauteur> hauteurs_possibles,std::vector<Couleur> couleurs_possibles) = 0;
};

#endif // JOUEURHUMAINGRAPHIQUE_H
