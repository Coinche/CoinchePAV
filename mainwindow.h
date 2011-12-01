#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include <QMap>
#include <QString>
#include <QPushButton>
#include <QRadioButton>
#include "donneurgraphique.h"
#include "joueurhumaingraphique.h"
#include "joueuriagraphique.h"
#include "startdialog.h"
#include "joueurHumain.h"
#include "joueurIA.h"
#include "donneur.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow,public DonneurGraphique,public JoueurHumainGraphique,public JoueurIAGraphique
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void afficherCarte(int joueur, Carte carte);
    virtual void afficherAnnonce(int joueur, Annonce annonce);

    virtual int afficherMainEtJouer(Main main,std::vector<bool> jouable);
    virtual void afficherMain(Main main,std::vector<bool> jouable);
    virtual Annonce afficherAnnonceEtParler(std::vector<Hauteur> hauteurs_possibles,std::vector<Couleur> couleurs_possibles);

    virtual void afficherMain(Main main);
    virtual void ramasserPli();
    virtual void init_game();
    virtual void afficherScores(int attaque, int defense);

private slots:
    void on_Carte0_clicked();

    void on_Carte1_clicked();

    void on_Carte2_clicked();

    void on_Carte3_clicked();

    void on_Carte4_clicked();

    void on_Carte5_clicked();

    void on_Carte6_clicked();

    void on_Carte7_clicked();

    void on_action_New_activated();

private:
    Ui::MainWindow *ui;
    QLabel* Pli_Joueur[4];
    QLabel* DPli_Joueur[4];
    QPushButton* Carte_Jeu[8];
    QMap<Couleur,QString> mapCouleur;
    QMap<Valeur,QString> mapValeur;
    QMap<Hauteur,QString> mapHauteur;

    QMap<Couleur,QRadioButton*> mapAnnonceCouleur;

    int lastbutton_clicked;

    JoueurHumain joueur_principal;
    IA* npp[3];

    Doner kebab;

private:

};

#endif // MAINWINDOW_H
