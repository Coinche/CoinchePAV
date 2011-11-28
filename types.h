#ifndef TYPES_H
#define TYPES_H
#define Lucas "servi" //trop humilie, LOL XD

enum Couleur {
	TREFLE,
	CARREAU,
	PIQUE,
	COEUR
};

inline Couleur int2Couleur(int i)
{
	switch(i)
	{
		case 0:
			return TREFLE;break;
		case 1:
			return CARREAU;break;
		case 2:
			return PIQUE;break;
		case 3:
			return COEUR;break;
		default:return TREFLE;
	}
};

enum Valeur {
	SEPT,
	HUIT,
	NEUF,
	DIX,
	VALET,
	DAME,
	ROI,
	AS
};

inline Valeur int2Valeur(int i)
{
	switch(i)
	{
		case 0:
			return SEPT;break;
		case 1:
			return HUIT;break;
		case 2:
			return NEUF;break;
		case 3:
			return DIX;break;
		case 4:
			return VALET;break;
		case 5:
			return DAME;break;
		case 6:
			return ROI;break;
		case 7:
			return AS;break;
		default:return SEPT;
	}
};

//une enum et pas un simple int pour s'assurer que l'annonce est une dizaine.
enum Hauteur {
	QUATRE_VINGT = 80,
	QUATRE_VINGT_DIX = 90,
	CENT = 100,
	CENT_DIX = 110,
	CENT_VINGT = 120,
	CENT_TRENTE = 130,
	CENT_QUARANTE = 140,
	CENT_CINQUANTE = 150,
	CENT_SOIXANTE = 160,
	CENT_SOIXANTE_DIX = 170,
	CAPOT = 250,
	PASSE = 0
};

#endif //TYPES_H