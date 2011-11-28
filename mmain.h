#ifndef MMAIN_H
#define MMAIN_H


#include <vector>
#include "carte.h"

class Main
{
	public:
		Main();
		~Main();
		Main(const Main&);
		//Main& operator=(const Main&);
		
		Carte& operator[](unsigned int n){return conteneur[n];};
		const Carte& operator[](unsigned int n) const{return conteneur[n];};
		
		inline void push_back(const Carte& carte){conteneur.push_back(carte);};
		inline unsigned int size() const {return conteneur.size();};
		inline bool empty() const {return conteneur.empty();};
		
		void enlever(const Carte&);
		void trierParCouleur();
		Main extraire(Couleur);
		bool contient(const Carte&) const;
		
	private:
		std::vector<Carte> conteneur;
};

bool operator==(const Main &main1, const Main &main2);

#endif