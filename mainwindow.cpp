//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include "mainwindow.h"

#include <fstream>
#include <QMessageBox>
#include <QPixmap>
#include "Equipe.h"
#include "Joueur.h"
#include "ResultatMatch.h"
#include "Simulation.h"
#include "ui_MainWindow.h"


// Constructeur
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Enlever la modif des titres
    ui->TitreSim->setEnabled(false);
    ui->TitreSim_2->setEnabled(false);
    ui->TitreSim_3->setEnabled(false);
    ui->TitreTableauCoachs->setEnabled(false);
    ui->TitreTableauJoueurs->setEnabled(false);
    ui->TxtAlignement->setEnabled(false);
    ui->TitreRemplacement->setEnabled(false);
    ui->TitreRooster->setEnabled(false);
    afficherDonnees();

    // Toujours commencer à la première page
    ui->MultiPageWidget->setCurrentIndex(0);

    // Deuxieme page/lineup/liste de rooster
    _equipe.charger("../equipe1.csv");
    chargerJoueursDepuisEquipe();
    remplirListeRoster();
    initialiserLineup();
    rafraichirUI();
    initialiserProgressBar();

    // Changements
    connect(ui->ListeRooster, &QListWidget::itemChanged, this, &MainWindow::verifierLimiteRoster);

    // Boutons pour changements
    connect(ui->BoutonLW, &QPushButton::clicked, this, [this]() {
    _joueurActif = _lineup[0];
    _positionSelectionnee = "LW";
    afficherRemplacements("LW");});
    connect(ui->BoutonC, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[1];
        _positionSelectionnee = "C";
        afficherRemplacements("C");});
    connect(ui->BoutonRW, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[2];
        _positionSelectionnee = "RW";
        afficherRemplacements("RW");});
    connect(ui->BoutonD1, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[3];
        _positionSelectionnee = "D";
        afficherRemplacements("D");});
    connect(ui->BoutonD2, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[4];
        _positionSelectionnee = "D";
        afficherRemplacements("D");});
    connect(ui->BoutonG, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[5];
        _positionSelectionnee = "G";
        afficherRemplacements("G");});

    // Trouver un joueur de la meme position pour changer
    connect(ui->listeWidget, &QListWidget::itemClicked, this,[this](QListWidgetItem* item){
    Joueur* nouveau = trouverJoueur(item->text().toStdString());
    if (!nouveau || !_joueurActif) return;

    for (int i = 0; i < _lineup.size(); i++) {
        if (_lineup[i]->getNumero() == _joueurActif->getNumero()) {
            Joueur* ancien = _lineup[i];
            _lineup[i] = nouveau;
            _disponibles.push_back(ancien);
            enleverDisponible(nouveau);
            _joueurActif = nullptr;
            break;
        }
    }
        rafraichirUI();
        remplirListeRoster();
    });

    // 3 Boutons pour naviguer dans les pages
    connect(ui->BoutonPageSim, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(1);});
    connect(ui->BoutonSim, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(2);
        ui->BoutonSim->setEnabled(false);
        Simulation simulation;

        QLabel* labels[] = {ui->LabelResult1,ui->LabelResult2,ui->LabelResult3,ui->LabelResult4,ui->LabelResult5,ui->LabelResult6,ui->LabelResult7,ui->LabelResult8,ui->LabelResult9,ui->LabelResult10};

        int index = 0;
        std::vector<std::string> ligne(4);

        while (!simulation.getCalendrier().empty() && index < 10) {
            ligne.clear();
            ligne.push_back("Montreal Quebecois");
            ligne.push_back(simulation.getCalendrier().front().getNomEquipe());

            ResultatMatch resultat =simulation.simulerMatch(_equipe.getPersonnes());
            QString texte;

            ligne.push_back(std::to_string(resultat.getScoreLocal()) + "-" + std::to_string(resultat.getScoreAdverse()));
            if (resultat.getGagnant()) {
                texte = "Victoire de votre équipe! ";
                ligne.push_back("V");
            } else {
                texte = "Défaite de votre équipe! ";
                ligne.push_back("D");
            }
            texte += QString::number(resultat.getScoreLocal());
            texte += " - ";
            texte += QString::number(resultat.getScoreAdverse());
            labels[index]->setText(texte);

            _sommaireSimu.push_back(ligne);
            index++;
        }
    });
    connect(ui->BoutonSauvegarder, &QPushButton::clicked,this, [this] () {
        std::ofstream fichierSauvegarde("../ResultatsMatchs.csv");
        if (!fichierSauvegarde.is_open()) {
            std::cerr << "L'ouverture du fichier a échoué." << std::endl;
            return;
        }
        for (const auto & match : _sommaireSimu) {
            for (size_t i = 0; i < match.size(); i++) {
                fichierSauvegarde << match[i];
                if (i < match.size()) {
                    fichierSauvegarde << ";";
                }
            }
            fichierSauvegarde << '\n';
        }
        fichierSauvegarde.close();
    });
    connect(ui->BoutonQuitter, &QPushButton::clicked, qApp, &QApplication::quit);

    // Affichage des images dans les labels
    QPixmap pix("C:/Users/mingo/CLionProjects/PROJET_HOCKEY_SIMULATOR/Images/chat.png");
    if (!pix.isNull()) {
        ui->ImageBackround->setPixmap(pix);
        ui->ImageBackround->setScaledContents(true);
    } else {
        qDebug() << "Image non chargée";
    }
    QPixmap pix2("C:/Users/mingo/CLionProjects/PROJET_HOCKEY_SIMULATOR/Images/ice.png");
    if (!pix2.isNull()) {
        ui->ImagePatinoire->setPixmap(pix2);
        ui->ImagePatinoire->setScaledContents(true);
    } else {
        qDebug() << "Image non chargée";
    }
    _breakingNews << "Caufield marque 2 buts contre les Ministers d'Ottawa" << "Slafkovsky en feu avec +3 dans ses deux derniers matchs"<< "Suzuki première étoile dans la dernière victoire des Québécois"<< "Laine blessé pour le reste de la saison";
    ui->News->setText(_breakingNews[0]);
    _timerNews = new QTimer(this);
    connect(_timerNews, &QTimer::timeout, this, &MainWindow::changerBreakingNews);
    _timerNews->start(5000);
    // Fin du constructeur
}

// Afficher la première page/tableaux des joueurs et entraîneurs
void MainWindow::afficherDonnees() const {
    ui->TableauJoueurs->setRowCount(0);
    ui->TableauEntraineurs->setRowCount(0);

    ui->TableauJoueurs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableauEntraineurs->setEditTriggers(QAbstractItemView::NoEditTriggers);

    Equipe equipeCharge;
    equipeCharge.charger("../equipe1.csv");

    int row = 0;
    int row2 = 0;
    for (auto personne : equipeCharge.getPersonnes()) {
        personne->afficher(ui->TableauJoueurs,ui->TableauEntraineurs,row,row2);
    }
}

//Charger les joueurs
void MainWindow::chargerJoueursDepuisEquipe() {
    _joueurs.clear();

    for (auto personne : _equipe.getPersonnes()) {
        auto* j = dynamic_cast<Joueur*>(personne);
        if (j != nullptr)
            _joueurs.push_back(j);
    }
}

// Le lineup sur la deuxieme page, le charger
void MainWindow::initialiserLineup() {
    _lineup.clear();
    _disponibles.clear();

    Joueur* lw = nullptr;
    Joueur* c = nullptr;
    Joueur* rw = nullptr;
    Joueur* d1 = nullptr;
    Joueur* d2 = nullptr;
    Joueur* g = nullptr;

    for (auto j : _joueurs) {
        std::string pos = j->getPosition();

        if (pos == "LW" && !lw) lw = j;
        else if (pos == "C" && !c) c = j;
        else if (pos == "RW" && !rw) rw = j;
        else if (pos == "D" && !d1) d1 = j;
        else if (pos == "D" && !d2) d2 = j;
        else if (pos == "G" && !g) g = j;
        else _disponibles.push_back(j);
    }

    _lineup = { lw, c, rw, d1, d2, g };
}

// Swap pour le remplacement
void MainWindow::afficherRemplacements(const std::string& position) {
    ui->listeWidget->clear();

    for (auto j : _disponibles) {
        if (j->getPosition() == position) {
            QString texte = QString::fromStdString(j->getNom() + " | OVR " + std::to_string(j->getOVR()));

            ui->listeWidget->addItem(texte);
        }
    }
}

Joueur* MainWindow::trouverJoueur(const std::string& texte) {
    for (auto j : _joueurs) {
        std::string nom = j->getNom() + " | OVR " + std::to_string(j->getOVR());
        if (texte == nom)
            return j;
    }
    return nullptr;
}

void MainWindow::enleverDisponible(Joueur* j) {
    for (auto it = _disponibles.begin(); it != _disponibles.end(); ++it) {
        if (*it == j) {
            _disponibles.erase(it);
            return;
        }
    }
}

// Quand on change un joueur, il s'affiche sur le bouton
void MainWindow::rafraichirUI() {
    auto format = [](Joueur* j) {
        if (!j) return QString("VIDE");
        return QString::fromStdString(j->getNom() + "\nOVR " + std::to_string(j->getOVR()));
    };
    ui->BoutonLW->setText(format(_lineup[0]));
    ui->BoutonC->setText(format(_lineup[1]));
    ui->BoutonRW->setText(format(_lineup[2]));
    ui->BoutonD1->setText(format(_lineup[3]));
    ui->BoutonD2->setText(format(_lineup[4]));
    ui->BoutonG->setText(format(_lineup[5]));
}

// Utilisation des listes joueursMatch et joueursReserve dans MainWindow.h
void MainWindow::sauvegarderSelectionRoster() {
    _joueursMatch.clear();
    _joueursReserve.clear();

    auto itJoueur = _joueurs.begin();

    for (int i = 0; i < ui->ListeRooster->count(); i++) {
        if (itJoueur == _joueurs.end())
            break;
        QListWidgetItem* item = ui->ListeRooster->item(i);
        if (item->checkState() == Qt::Checked)
            _joueursMatch.push_back(*itJoueur);
        else
            _joueursReserve.push_back(*itJoueur);
        itJoueur++;
    }
}

// Remplir la liste du roster sur la page 2
void MainWindow::remplirListeRoster() {
    ui->ListeRooster->clear();

    for (auto j : _joueurs) {
        QString texte = QString::fromStdString(j->getNom() + " | " + j->getPosition() + " | OVR " + std::to_string(j->getOVR()));
        auto* item = new QListWidgetItem(texte);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        if (estDansLineup(j))
            item->setCheckState(Qt::Checked);
        else
            item->setCheckState(Qt::Unchecked);

        ui->ListeRooster->addItem(item);
    }
}

// S'assurer que le roster ne depasse pas 20 joueurs + conditions
void MainWindow::verifierLimiteRoster(QListWidgetItem* item) {
    int nbCoches = 0;
    int nbGardiens = 0;
    int nbDefenseurs = 0;

    // Le bouton n'est pas dispo, il faut 20 joueurs cochés pour qu'il marche
    ui->BoutonSim->setEnabled(false);

    for (int i = 0; i < ui->ListeRooster->count(); i++) {
        if (ui->ListeRooster->item(i)->checkState() == Qt::Checked) {
            nbCoches++;
            std::string position = _joueurs[i]->getPosition();
            if(position == "G")
                nbGardiens++;
            if(position == "D")
                nbDefenseurs++;
        }
    }

    // Maximum 20
    if (nbCoches > 20) {
        item->setCheckState(Qt::Unchecked);
        QMessageBox::warning(this,"Limite atteinte","Maximum de 20 joueurs.");

        return;
    }

    // Validation visuelle quand roster complet
    if(nbCoches == 20) {
        ui->BoutonSim->setEnabled(true);
        if(nbGardiens < 1) {
            QMessageBox::warning(this,"Roster invalide", "Vous devez avoir au moins 1 gardien.");
        } else if(nbDefenseurs < 6) {
            QMessageBox::warning(this,"Roster invalide","Vous devez avoir au moins 6 defenseurs.");
        } else {
            QMessageBox::information(this,"Roster valide","Votre roster est valide.");
        }
    }
}

bool MainWindow::estDansLineup(Joueur* j) {
    for (auto l : _lineup) {
        if (l == j)
            return true;
    }
    return false;
}

void MainWindow::changerBreakingNews()
{
    _indexNews++;

    if(_indexNews >= _breakingNews.size())
        _indexNews = 0;

    ui->News->setText(_breakingNews[_indexNews]);
}

void MainWindow::initialiserProgressBar() {
    int matchsJoues = 10;
    int totalMatchs = 10;
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(totalMatchs);
    ui->progressBar->setValue(matchsJoues);
    ui->progressBar->setFormat(QString("Saison : %1 / %2 matchs").arg(matchsJoues).arg(totalMatchs));
    ui->progressBar->setTextVisible(true);
}

MainWindow::~MainWindow() {
    delete ui;
}