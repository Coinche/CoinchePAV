#ifndef CARTE_H
#define CARTE_H

#include <vector>
#include "types.h"

class Carte {
private:
        Valeur  valeur;
        Couleur couleur;

public:
        // les attributs publics sont const pour ne pas qu'un joueur puisse modifier ses cartes

        Carte(Valeur, Couleur); //constructeur
        Carte(const Carte& carte); //constructeur par copie
        Valeur get_valeur() const;
        Couleur get_couleur() const;
};

// Pli et Main sont differents semantiquement (dans le diagramme UML), meme si en fait derriere c'est la meme classe.
// les typedef sont la pour clarifier la suite.
//eventuellement, si on trouve ca mieux, on peut remplacer vector par list sans rien casser ailleurs (si c'est bien code)
typedef std::vector<Carte> Pli;
typedef std::vector<Carte> Main;

#endif //CARTE_H
