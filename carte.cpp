#include "carte.h"

Carte::Carte(Valeur val, Couleur coul) :	valeur(val), couleur(coul)
{}



 Carte::Carte(const Carte& carte) : valeur(carte.valeur), couleur(carte.couleur)
 {}

Valeur Carte::get_valeur() const
{
    return valeur;

}
Couleur Carte::get_couleur() const
{

    return couleur;
}
