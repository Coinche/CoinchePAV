#ifndef TYPES_H
#define TYPES_H
#define Lucas "servi" //trop humilie, LOL XD

enum Couleur {
	TREFLE,
	CARREAU,
	PIQUE,
	COEUR
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

//une enum et pas un simple int pour s'assurer que l'annonce est une dizaine.
enum Hauteur {
	QUATRE_VINGT = 80,
	QUATRE_VINGT_DIX = 90,
	CENT = 100,
	CENT_DIX = 110,
	CENT_VINGT = 120,
	CENT_TRENTE = 130,
	CENT_QUARANTE = 140,
	CENT_CINQANTE = 150,
	CENT_SOIXANTE = 160,
	CENT_SOIXANTE_DIX = 170,
	CAPOT = 250,
	PASSE = 0
};

#endif //TYPES_H