#ifndef MMAIN_H
#define MMAIN_H


#include <vector>
#include "carte.h"

class Main
{
	public:
		Main();
		Main(const Main&);
		//Main& operator=(const Main&);

                Carte& operator[](unsigned int n);
                const Carte& operator[](unsigned int n) const;

                void push_back(const Carte& carte);
                unsigned int size() const;
                bool empty() const;

		void enlever(const Carte&);
		void trierParCouleur();
		Main extraire(Couleur) const;
                bool contient(Carte) const;

	private:
		std::vector<Carte> conteneur;
};

bool operator==(const Main &main1, const Main &main2);

#endif
