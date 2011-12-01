#include "mmain.h"
#include <algorithm>

using namespace std;

Main::Main():conteneur(){}

Main::Main(const Main& Main)
: conteneur(Main.conteneur)
{}

Carte& Main::operator[](unsigned int n){return conteneur[n];}
const Carte& Main::operator[](unsigned int n) const{return conteneur[n];}

void Main::push_back(const Carte& carte){conteneur.push_back(carte);}
unsigned int Main::size() const {return conteneur.size();}
bool Main::empty() const {return conteneur.empty();}


void Main::enlever(const Carte& carte)
{
	conteneur.erase(
		find(
			conteneur.begin(),
			conteneur.end(),
			carte
		)
	);
}

void Main::trierParCouleur()
{
	sort(conteneur.begin(), conteneur.end(), Carte::triParCouleur);
}

Main Main::extraire(Couleur couleur) const
{
	Main resultat;
	for(unsigned int i=0; i<conteneur.size(); i++)
		if(conteneur[i].get_couleur() == couleur)
			resultat.push_back(conteneur[i]);
	return resultat;
}

bool Main::contient(Carte carte) const
{
	return ( count(
		conteneur.begin(),
		conteneur.end(),
		carte
		) != 0 );
}

bool operator==(const Main &main1, const Main &main2)
{
	bool reponse = true;
	if(main1.size() != main2.size())
	{
	    return false;
	}
	else
	{
	    unsigned int index1 = 0;
        while( reponse && ( index1<main1.size() ) )
        {
            bool reponsecarte = false;
            for (unsigned int index2 = 0; index2<main2.size(); index2++)
            {
                reponsecarte|=( main1[index1] ==main2[index2] );
            }
            reponse&=reponsecarte;
            index1++;

        }
        return reponse;
	}

}
