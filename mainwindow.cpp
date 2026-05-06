//
// Created by Utilisateur on 2026-04-24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved
#include "mainwindow.h"

#include <QPushButton>
#include <QPixmap>
#include "Equipe.h"
#include "Joueur.h"
#include "ui_MainWindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Enlever la modif des titres
    ui->TitreSim->setEnabled(false);
    ui->TitreSim_2->setEnabled(false);
    ui->TitreSim_3->setEnabled(false);
    ui->TitreTableauCoachs->setEnabled(false);
    ui->TitreTableauJoueurs->setEnabled(false);
    ui->TxtAlignement->setEnabled(false);
    afficherDonnees();

    // Deuxieme page/lineup
    _equipe.charger("../equipe1.csv");
    chargerJoueursDepuisEquipe();
    initialiserLineup();
    rafraichirUI();
    connect(ui->BoutonLW, &QPushButton::clicked, this, [this]() {
    _joueurActif = _lineup[0];
    _positionSelectionnee = "LW";
    afficherRemplacements("LW");
    });
    connect(ui->BoutonC, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[1];
        _positionSelectionnee = "C";
        afficherRemplacements("C");
    });
    connect(ui->BoutonRW, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[2];
        _positionSelectionnee = "RW";
        afficherRemplacements("RW");
    });
    connect(ui->BoutonD1, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[3];
        _positionSelectionnee = "D";
        afficherRemplacements("D");
    });
    connect(ui->BoutonD2, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[4];
        _positionSelectionnee = "D";
        afficherRemplacements("D");
    });
    connect(ui->BoutonG, &QPushButton::clicked, this, [this]() {
        _joueurActif = _lineup[5];
        _positionSelectionnee = "G";
        afficherRemplacements("G");
    });
    connect(ui->listeWidget, &QListWidget::itemClicked, this,
[this](QListWidgetItem* item)
{
    Joueur* nouveau = trouverJoueur(item->text().toStdString());
    if (!nouveau || !_joueurActif) return;
    // Trouver index du joueur actif
    for (int i = 0; i < _lineup.size(); i++)
    {
        if (_lineup[i] == _joueurActif)
        {
            Joueur* ancien = _lineup[i];
            _lineup[i] = nouveau;
            _disponibles.push_back(ancien);
            enleverDisponible(nouveau);
            break;
        }
    }

    rafraichirUI();
});

    // 3 Boutons pour naviguer dans les pages
    connect(ui->BoutonPageSim, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(1);
    });
    connect(ui->BoutonSim, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(2);
    });
    connect(ui->BoutonAccueil, &QPushButton::clicked, this, [this]() {
        ui->MultiPageWidget->setCurrentIndex(0);
    });
    // Affichage des images dans les labels
    QPixmap pix("C:/Users/mingo/CLionProjects/PROJET_HOCKEY_SIMULATOR/Images/chat.png");
    if (!pix.isNull()) {
        ui->ImageBackround->setPixmap(pix);
        ui->ImageBackround->setScaledContents(true);
    } else {
        qDebug() << "Image non chargée";
    }
    QPixmap pix2("C:/Users/mingo/CLionProjects/PROJET_HOCKEY_SIMULATOR/Images/ice.png");
    if (!pix.isNull()) {
        ui->ImagePatinoire->setPixmap(pix2);
        ui->ImagePatinoire->setScaledContents(true);
    } else {
        qDebug() << "Image non chargée";
    }
    // Fin du constructeur
}

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
        if (personne->getNumero() != 0) {
            ui->TableauJoueurs->insertRow(row);
            ui->TableauJoueurs->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(personne->getNom())));
            ui->TableauJoueurs->setItem(row, 1, new QTableWidgetItem(QString::number(personne->getNumero())));
            ui->TableauJoueurs->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(personne->getPosition())));
            row++;
        } else {
            ui->TableauEntraineurs->insertRow(row2);
            ui->TableauEntraineurs->setItem(row2, 0, new QTableWidgetItem(QString::fromStdString(personne->getNom())));
            ui->TableauEntraineurs->setItem(row2, 1, new QTableWidgetItem(QString::fromStdString(personne->getPosition())));
            row2++;
        }
    }
}

void MainWindow::chargerJoueursDepuisEquipe() {
    _joueurs.clear();

    for (auto personne : _equipe.getPersonnes())
    {
        Joueur* j = dynamic_cast<Joueur*>(personne);
        if (j != nullptr)
            _joueurs.push_back(j);
    }
}

void MainWindow::initialiserLineup() {
    _lineup.clear();
    _disponibles.clear();

    for (auto j : _joueurs)
    {
        if (_lineup.size() < 5) // test simple
            _lineup.push_back(j);
        else
            _disponibles.push_back(j);
    }
}

void MainWindow::afficherRemplacements(const std::string& position) {
    ui->listeWidget->clear();

    for (auto j : _disponibles)
    {
        if (j->getPosition() == position)
        {
            QString texte = QString::fromStdString(
                j->getNom() + " #" + std::to_string(j->getNumero())
            );

            ui->listeWidget->addItem(texte);
        }
    }
}

Joueur* MainWindow::trouverJoueur(const std::string& texte) {
    for (auto j : _joueurs)
    {
        std::string nom = j->getNom() + " #" + std::to_string(j->getNumero());

        if (texte == nom)
            return j;
    }
    return nullptr;
}

void MainWindow::enleverDisponible(Joueur* j) {
    for (auto it = _disponibles.begin(); it != _disponibles.end(); ++it)
    {
        if (*it == j)
        {
            _disponibles.erase(it);
            return;
        }
    }
}

void MainWindow::rafraichirUI() {
    ui->BoutonLW->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
    ui->BoutonC->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
    ui->BoutonRW->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
    ui->BoutonD1->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
    ui->BoutonD2->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
    ui->BoutonG->setText(QString::fromStdString(_lineup[0]->getNom() + " #" + std::to_string(_lineup[0]->getNumero())));
}

MainWindow::~MainWindow() {
    delete ui;
}