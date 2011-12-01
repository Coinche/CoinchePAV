#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //GroupBox non visibles au démarrage..il faut utiliser Servir
    ui->groupBoxAnnonce->setVisible(false);
    ui->groupBoxDPli->setVisible(false);

    //configuration des objets metier
    joueur_principal.set_joueurHG(this);
    kebab.set_donneurGraphique(this);
    npp[0] = new IA_intermediate();
    npp[1] = new IA_intermediate();
    npp[2] = new IA_intermediate();
    kebab.set_joueurs(&joueur_principal, npp[0], npp[1], npp[2]);
    for(int i=0; i<3; i++)
        npp[i]->set_donneur(&kebab);

    //Adressage des différentes Carte + mappage couleur pour pouvoir boucler/accéder rapidement
    Pli_Joueur[0] = ui->Pli_Joueur0;
    Pli_Joueur[1] = ui->Pli_Joueur1;
    Pli_Joueur[2] = ui->Pli_Joueur2;
    Pli_Joueur[3] = ui->Pli_Joueur3;

    Carte_Jeu[0] = ui->Carte0;
    Carte_Jeu[1] = ui->Carte1;
    Carte_Jeu[2] = ui->Carte2;
    Carte_Jeu[3] = ui->Carte3;
    Carte_Jeu[4] = ui->Carte4;
    Carte_Jeu[5] = ui->Carte5;
    Carte_Jeu[6] = ui->Carte6;
    Carte_Jeu[7] = ui->Carte7;

    DPli_Joueur[0] = ui->DPli_Joueur0;
    DPli_Joueur[1] = ui->DPli_Joueur1;
    DPli_Joueur[2] = ui->DPli_Joueur2;
    DPli_Joueur[3] = ui->DPli_Joueur3;

    mapAnnonceCouleur.insert(COEUR,ui->radioButtonCoeur);
    mapAnnonceCouleur.insert(CARREAU,ui->radioButtonCarreau);
    mapAnnonceCouleur.insert(PIQUE,ui->radioButtonPique);
    mapAnnonceCouleur.insert(TREFLE,ui->radioButtonTrefle);

    mapCouleur.insert(COEUR, "coeur");
    mapCouleur.insert(CARREAU, "carreau");
    mapCouleur.insert(PIQUE, "pique");
    mapCouleur.insert(TREFLE, "trefle");

    mapValeur.insert(SEPT,"7");
    mapValeur.insert(HUIT,"8");
    mapValeur.insert(NEUF,"9");
    mapValeur.insert(DIX,"10");
    mapValeur.insert(VALET,"valet");
    mapValeur.insert(DAME,"dame");
    mapValeur.insert(ROI,"roi");
    mapValeur.insert(AS,"as");

    mapHauteur.insert(QUATRE_VINGT,"80");
    mapHauteur.insert(QUATRE_VINGT_DIX,"90");
    mapHauteur.insert(CENT,"100");
    mapHauteur.insert(CENT_DIX,"110");
    mapHauteur.insert(CENT_VINGT,"120");
    mapHauteur.insert(CENT_TRENTE,"130");
    mapHauteur.insert(CENT_QUARANTE,"140");
    mapHauteur.insert(CENT_CINQUANTE,"150");
    mapHauteur.insert(CENT_SOIXANTE,"160");
    mapHauteur.insert(CENT_SOIXANTE_DIX,"170");
    mapHauteur.insert(CAPOT,"Capot");
    mapHauteur.insert(PASSE,"Passe");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_activated()
{
    StartDialog startDialog(this);
    QStringList info;
    if (startDialog.exec() == QDialog::Accepted)
        info = startDialog.readSettings();
    // dialog accepté, info contient les infos nécessaires !
    //Initialisation du Jeu !
    //init_game();
    kebab.jouerUnePartie();
}

void MainWindow::init_game()
{
    //Box annonces DPli visibles
    ui->groupBoxAnnonce->setVisible(true);
    ui->groupBoxDPli->setVisible(true);
    //On Désactive les Annonces
    ui->radioButtonCarreau->setEnabled(false);
    ui->radioButtonCoeur->setEnabled(false);
    ui->radioButtonPique->setEnabled(false);
    ui->radioButtonTrefle->setEnabled(false);

    //On supprime la pix des cartes du pli et de dernier pli
    for (int i=0; i<4;i++)
    {
        Pli_Joueur[i]->setPixmap(QPixmap());
        DPli_Joueur[i]->setPixmap(QPixmap());
    }
    //Init Graph des jeux IA
    ui->Jeu2->setPixmap(QPixmap(":/new/prefix1/Resources/Cartes/dos/dos8v.jpg") );
    ui->Jeu3->setPixmap(QPixmap(":/new/prefix1/Resources/Cartes/dos/dos8.jpg") );
    ui->Jeu4->setPixmap(QPixmap(":/new/prefix1/Resources/Cartes/dos/dos8v.jpg") );
    ui->LabelScore->setText("");
    ui->listWidgetAnnonce->clear();
}

void MainWindow::afficherScores(int attaque, int defense)
{
    ui->LabelScore->setText("N "+QString::number(attaque)+"  E "+QString::number(defense));
}

void MainWindow::afficherCarte(int joueur,Carte carte)
{
    Pli_Joueur[joueur]->setPixmap(QPixmap(":/new/prefix1/Resources/Cartes/"+
                                          mapCouleur[carte.get_couleur()]+"/"+
                                          mapValeur[carte.get_valeur()]+".png"));

    //Pli_Joueur[joueur]->repaint();
    Pli_Joueur[joueur]->raise();
}

void MainWindow::afficherAnnonce(int joueur,Annonce annonce)
{
    QString dAnnonce;
    if (annonce.get_hauteur() == PASSE)
    {
        dAnnonce = "Joueur "+QString::number(joueur)+" passe comme un pd";
    }
    else{
        dAnnonce = "Joueur "+QString::number(joueur)+" "+mapHauteur[annonce.get_hauteur()]+" "+mapCouleur[annonce.get_couleur()];
    }
    ui->listWidgetAnnonce->addItem(dAnnonce);
    ui->label_Annonce->setText(dAnnonce);
}

void MainWindow::ramasserPli()
{

    //Ramassage du pli et placement en position dernier pli !
    for (int i=0; i<4; i++)
    {
        const QPixmap* mPixmap = Pli_Joueur[i]->pixmap();
        DPli_Joueur[i]->setPixmap(*mPixmap);
        Pli_Joueur[i]->clear();
    }
}

//JoueurHumainGraphique

int MainWindow::afficherMainEtJouer(Main main,std::vector<bool> jouable)
    {
        afficherMain(main,jouable);
        QEventLoop myLoop;
        for (unsigned int i=0; i<main.size(); i++)
        {
            QObject::connect(Carte_Jeu[i], SIGNAL(clicked()), &myLoop, SLOT(quit()));
        }
        /*for (unsigned int i=0; i<main.size(); i++)
        {
            Carte_Jeu[i]->setIcon(QIcon(":/new/prefix1/Resources/Cartes/"+
                                        mapCouleur[main[i].get_couleur()]+"/"+
                                        mapValeur[main[i].get_valeur()]+".png"));
            Carte_Jeu[i]->setEnabled(jouable[i]);

            QObject::connect(Carte_Jeu[i], SIGNAL(clicked()), &myLoop, SLOT(quit()));
        }
        //On désactive les boutons correspondant aux carte déjà jouées !
        for (unsigned int i=main.size(); i < 8; i++)
        {
            Carte_Jeu[i]->setVisible(false);
        }
        */
        myLoop.exec();
        Carte_Jeu[lastbutton_clicked]->setIcon(QIcon());
        return lastbutton_clicked;
    }

    void MainWindow::afficherMain(Main main,std::vector<bool> jouable)
    {
        for (unsigned int i=0; i<main.size(); i++)
                {
                    Carte_Jeu[i]->setIcon(QIcon(":/new/prefix1/Resources/Cartes/"+
                                                mapCouleur[main[i].get_couleur()]+"/"+
                                                mapValeur[main[i].get_valeur()]+".png"));
                    Carte_Jeu[i]->setVisible(true);
                    Carte_Jeu[i]->setEnabled(jouable[i]);
                }
                //On désactive les boutons correspondant aux carte déjà jouées !
                for (unsigned int i=main.size(); i < 8; i++)
                {
                    Carte_Jeu[i]->setVisible(false);
                }
    }

    Annonce MainWindow::afficherAnnonceEtParler(std::vector<Hauteur> hauteurs_possibles,std::vector<Couleur> couleurs_possibles)
    {
        QEventLoop myLoop;
        ui->comboBoxAnnonce->clear();
        mapAnnonceCouleur[CARREAU]->setEnabled(false);
        mapAnnonceCouleur[COEUR]->setEnabled(false);
        mapAnnonceCouleur[PIQUE]->setEnabled(false);
        mapAnnonceCouleur[TREFLE]->setEnabled(false);

        for (unsigned int i=0; i<hauteurs_possibles.size(); i++)
        {
            ui->comboBoxAnnonce->addItem(mapHauteur[hauteurs_possibles[i]]);
        }
        for (unsigned int j=0; j<couleurs_possibles.size();j++)
        {
            mapAnnonceCouleur[couleurs_possibles[j]]->setEnabled(true);
            mapAnnonceCouleur[couleurs_possibles[j]]->setChecked(true);
        }
        QObject::connect(ui->SpeakButton, SIGNAL(clicked()), &myLoop, SLOT(quit()));
        myLoop.exec();

        Couleur couleur_choisie;

        if (ui->radioButtonCarreau->isChecked()) couleur_choisie = CARREAU;

        if (ui->radioButtonCoeur->isChecked()) couleur_choisie = COEUR;

        if (ui->radioButtonPique->isChecked()) couleur_choisie = PIQUE;

        if (ui->radioButtonTrefle->isChecked()) couleur_choisie = TREFLE;

        if (ui->comboBoxAnnonce->currentText() == "Passe")
        {
            return Annonce(PASSE,couleur_choisie);
        }
        else if (ui->comboBoxAnnonce->currentText() == "Capot")
        {
            return Annonce(CAPOT,couleur_choisie);
        }
        else
        {
            return Annonce((Hauteur) ui->comboBoxAnnonce->currentText().toInt(),couleur_choisie);
        }
    }

//JoueurIAGraphique

void MainWindow::afficherMain(Main main)
{

    for (unsigned int i=0; i<main.size(); i++) {
        Carte_Jeu[i]->setIcon(QIcon(":/new/prefix1/Resources/Cartes/"+
                                    mapCouleur[main[i].get_couleur()]+"/"+
                                    mapValeur[main[i].get_valeur()]+".png"));
        Carte_Jeu[i]->setEnabled(true);
    }
    //On désactive les boutons correspondant aux carte déjà jouées !
}

void MainWindow::on_Carte0_clicked()
{
    // On détruit la carte..ici donneur graphique le fait
    //Carte_Jeu[0]->setIcon(QIcon());
    lastbutton_clicked = 0;

}

void MainWindow::on_Carte1_clicked()
{
    //Carte_Jeu[1]->setIcon(QIcon());
    lastbutton_clicked = 1;
}

void MainWindow::on_Carte2_clicked()
{
    //Carte_Jeu[2]->setIcon(QIcon());
    lastbutton_clicked = 2;
}

void MainWindow::on_Carte3_clicked()
{
    //Carte_Jeu[3]->setIcon(QIcon());
    lastbutton_clicked = 3;
}

void MainWindow::on_Carte4_clicked()
{
    //Carte_Jeu[4]->setIcon(QIcon());
    lastbutton_clicked = 4;
}

void MainWindow::on_Carte5_clicked()
{
    //Carte_Jeu[5]->setIcon(QIcon());
    lastbutton_clicked = 5;
}

void MainWindow::on_Carte6_clicked()
{
    //Carte_Jeu[6]->setIcon(QIcon());
    lastbutton_clicked = 6;
}

void MainWindow::on_Carte7_clicked()
{
    //Carte_Jeu[7]->setIcon(QIcon());
    lastbutton_clicked = 7;
}

