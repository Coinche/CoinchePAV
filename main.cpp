#include <iostream>

#include"types.h"
#include"annonce.h"
#include "debugage.h"


using namespace std;

int main()
{
    /*cout << "Hello world!" << endl;
    Annonce pd(QUATRE_VINGT,CARREAU);
    Annonce cojones(CENT_SOIXANTE_DIX,TREFLE);
    cout << "La couleur du pd : " << pd.couleur << endl;
    cout << "cojones est plus couillu que pd : " << (cojones>pd) << endl;
    */
    cout << "Initialisation :" << endl;
    bool status = Debugage::debugage();
    cout << "Status : " << status << endl;
    return 0;
}