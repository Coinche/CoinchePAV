#include"annonce.h"


//Constructeur
Annonce::Annonce(Hauteur h, Couleur c): hauteur(h), couleur(c)
{
}

//Méthodes
bool Annonce::operator>(const Annonce& annonce)
{
	return hauteur > annonce.hauteur ? true : false;
}
